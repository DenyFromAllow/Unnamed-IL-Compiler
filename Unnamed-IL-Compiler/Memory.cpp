#include "main.h"

void Ram(uint32 Instruction, String SourceString) {
	if(Instruction == 0xD0) {
		Memory < Variable();
	} else {
		Stack < Variable();
	}
	bool MultiPart = false;
	VarType type = getType(SourceString, 3);
	if(type == VarType::none) {
		MultiPart = true;
	} else if(type == VarType::error) {
		SourceString++;
		_getch();
		exit(0);
	} else if(type == VarType::f || type == VarType::df || type == VarType::ld) {
		SourceString++;
		_getch();
		exit(0);
	} else {
		if(Instruction == 0xD0) {
			Memory[Memory.length - 1].type = type;
		} else {
			Stack[Stack.length - 1].type = type;
		}
	}
	check();
	SourceReader->ReadWord(SourceString);
	if(SourceString.IsEmpty()) {
		printf("error");
		_getch();
		exit(0);
	}
	if((*SourceString.begin()) < '9' && (*SourceString.begin()) > '1') {
		SourceString++;
		_getch();
		exit(0);
	}
	if(Instruction == 0xD0) {
		Memory[Memory.length - 1].name = SourceString;
	} else {
		Stack[Stack.length - 1].name = SourceString;
	}

	if(!MultiPart) {
		check();
		SourceReader->ReadDECNumber(SourceString);
		bool getCountByData = false;
		uint32 ElementCount;
		if(SourceString.IsEmpty()) {
			ElementCount = 0;
		} else {
			SourceString.DECTouint32(ElementCount);
			if(ElementCount == 0) {
				SourceString++;
				_getch();
				exit(0);
			}
		}
		VarType DataType;
		check();
		SourceReader->ReadWord(SourceString);
		if(SourceString.IsEmpty()) {
			DataType = VarType::none;
		} else {
			if(!ElementCount) {
				SourceString++;
				_getch();
				exit(0);
			}
			DataType = getType(SourceString, 0);
			if(DataType == VarType::error || DataType == VarType::none) {
				if(MainTrie.findPrefix(SourceString.begin()) <= 0xff) {
					SourceReader->Back(SourceString.size());
					Memory[Memory.length - 1].ElementCount = ElementCount;
					Memory[Memory.length - 1].DataCount = 0;
					Memory[Memory.length - 1].data = nullptr;
					Memory[Memory.length - 1].next = nullptr;
					return;
				}
				SourceString++;
				_getch();
				exit(0);
			} else if(DataType == VarType::ptr) {
				SourceString++;
				_getch();
				exit(0);
			} else if(DataType == VarType::f || DataType == VarType::df || DataType == VarType::ld) {
				SourceString++;
				_getch();
				exit(0);
			}
		}
		char firstSeparator;
		SourceReader->ReadSeparator(firstSeparator);
		if(firstSeparator != '['&&firstSeparator != '('&&firstSeparator != '{'&&firstSeparator != '<') {
			if(!firstSeparator && DataType == VarType::none && ElementCount) {
				if(Instruction == 0xD0) {
					Memory[Memory.length - 1].ElementCount = ElementCount;
					Memory[Memory.length - 1].DataCount = 0;
					Memory[Memory.length - 1].data = nullptr;
					Memory[Memory.length - 1].next = nullptr;
				} else {
					Stack[Stack.length - 1].ElementCount = ElementCount;
					Stack[Stack.length - 1].DataCount = 0;
					Stack[Stack.length - 1].data = nullptr;
					Stack[Stack.length - 1].next = nullptr;
				}
				return;
			}
			printf("error");
			_getch();
			exit(0);
		}
		uint64 tempPointer = SourceReader->Pointer;
		uint32 DataCount = 0;

		for(char Separator;;) {
			SourceReader->SkipUntilSeparator();
			SourceReader->ReadSeparator(Separator);
			if(Separator == ',') {
				DataCount++;
			} else if(Separator == '\n') {
				continue;
			} else if((firstSeparator == '['&&Separator == ']') || (firstSeparator == '('&&Separator == ')') || (firstSeparator == '{'&&Separator == '}') || (firstSeparator == '<{'&&Separator == '>')) {
				DataCount++;
				break;
			} else {
				printf("error");
				_getch();
				exit(0);
			}
		}
		SourceReader->Pointer = tempPointer;
		if(DataType == VarType::none)DataType = type;
		if(DataCount == 1) {
			char Separator;
			check();
			SourceReader->ReadDECNumber(SourceString);
			check();
			SourceReader->ReadSeparator(Separator);
			if(SourceString.IsEmpty() && ElementCount && Separator) {
				if(Instruction == 0xD0) {
					Memory[Memory.length - 1].ElementCount = ElementCount;
					Memory[Memory.length - 1].DataCount = 0;
					Memory[Memory.length - 1].data = nullptr;
					Memory[Memory.length - 1].next = nullptr;
				} else {
					Stack[Stack.length - 1].ElementCount = ElementCount;
					Stack[Stack.length - 1].DataCount = 0;
					Stack[Stack.length - 1].data = nullptr;
					Stack[Stack.length - 1].next = nullptr;
				}
			} else if(!SourceString.IsEmpty() && Separator) {
				if(DataType > type) {
					printf("Too many data");
					_getch();
					exit(0);
				}
				if(Instruction == 0xD0) {
					Memory[Memory.length - 1].ElementCount = (ElementCount) ? ElementCount : 1;
					Memory[Memory.length - 1].DataCount = 1;
					Memory[Memory.length - 1].next = nullptr;
				} else {
					Stack[Stack.length - 1].ElementCount = (ElementCount) ? ElementCount : 1;
					Stack[Stack.length - 1].DataCount = 1;
					Stack[Stack.length - 1].next = nullptr;
				}
				uint64 value;
				SourceString.DECToint64(*((int64*) &value));
				if(type == VarType::ptr) {
					if(value) {
						printf("error");
						_getch();
						exit(0);
					} else {
						if(Instruction == 0xD0) {
							Memory[Memory.length - 1].data = nullptr;
						} else {
							Stack[Stack.length - 1].data = nullptr;
						}
					}
				} else {
					if(Instruction == 0xD0) {
						Memory[Memory.length - 1].data = allocByType(type, 1);
						assignByType(Memory[Memory.length - 1].data, 0, type, 0);
						assignByType(Memory[Memory.length - 1].data, value, DataType, 0);
					} else {
						Stack[Stack.length - 1].data = allocByType(type, 1);
						assignByType(Stack[Stack.length - 1].data, 0, type, 0);
						assignByType(Stack[Stack.length - 1].data, value, DataType, 0);
					}
				}
			} else {
				printf("error");
				_getch();
				exit(0);
			}
			return;
		}
		uint32 TrueDataCount;
		if(!ElementCount) {
			ElementCount = DataCount;
			TrueDataCount = DataCount;
		} else {
			uint16 typeSize = sizeOfType(type);
			uint16 DataTypeSize = sizeOfType(DataType);
			TrueDataCount = DataTypeSize * DataCount / typeSize;
			if(DataTypeSize * DataCount % typeSize)TrueDataCount++;
			if(TrueDataCount > ElementCount) {
				printf("Too many data");
				_getch();
				exit(0);
			}
		}

		if(Instruction == 0xD0) {
			Memory[Memory.length - 1].data = allocByType(type, TrueDataCount);
			assignByType(Memory[Memory.length - 1].data, 0ll, type, TrueDataCount - 1);
			Memory[Memory.length - 1].ElementCount = ElementCount;
			Memory[Memory.length - 1].DataCount = TrueDataCount;
			Memory[Memory.length - 1].next = nullptr;
		} else {
			Stack[Stack.length - 1].data = allocByType(type, TrueDataCount);
			assignByType(Stack[Stack.length - 1].data, 0ll, type, TrueDataCount - 1);
			Stack[Stack.length - 1].ElementCount = ElementCount;
			Stack[Stack.length - 1].DataCount = TrueDataCount;
			Stack[Stack.length - 1].next = nullptr;
		}

		for(uint32 DataIndex = 0;; DataIndex++) {
			char Separator;
			check();
			SourceReader->ReadDECNumber(SourceString);
			check();
			SourceReader->ReadSeparator(Separator);
			if(SourceString.IsEmpty() || !Separator) {
				printf("error");
				_getch();
				exit(0);
			} else {
				uint64 value;
				SourceString.DECToint64(*((int64*) &value));
				if(Instruction == 0xD0) {
					assignByType(Memory[Memory.length - 1].data, value, DataType, DataIndex);
				} else {
					assignByType(Stack[Stack.length - 1].data, value, DataType, DataIndex);
				}
				if(Separator != ',')break;
			}
		}
	}
}