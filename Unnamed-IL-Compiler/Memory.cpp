#include "main.h"

void Ram(uint32 Instruction, String SourceString) {
	Variable *thisVariable;
	if(Instruction == 0xD0) {
		Memory < Variable();
		thisVariable = &Memory[Memory.length - 1];
	} else {
		Stack < Variable();
		thisVariable = &Stack[Stack.length - 1];
	}
	bool IsFirstVariable = true;
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
		thisVariable->type = type;
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
	thisVariable->name = SourceString;

	do {
		check();
		if(MultiPart) {
			SourceReader->ReadWord(SourceString);
			if(IsFirstVariable) {
				if(Instruction == 0xD0) {
					if(SourceString[0] != 'r' || SourceString[1] != 'a' || SourceString[2] != 'm') {
						printf("error");
						_getch();
						exit(0);
					}
				} else {
					if(SourceString[0] != 'r' || SourceString[1] != 'a' || SourceString[2] != 'm') {
						printf("error");
						_getch();
						exit(0);
					}
				}
			}
			type = getType(SourceString, 3);
			if(type == VarType::none) {
				printf("error");
				_getch();
				exit(0);
			} else if(type == VarType::error) {
				SourceString++;
				_getch();
				exit(0);
			} else if(type == VarType::f || type == VarType::df || type == VarType::ld) {
				SourceString++;
				_getch();
				exit(0);
			} else {
				thisVariable->type = type;
			}
		}
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
		checkIgnEOT();
		if(SourceReader->EndOfText()) {
			thisVariable->ElementCount = ElementCount;
			thisVariable->DataCount = 0;
			thisVariable->data = nullptr;
			thisVariable->next = nullptr;
		}
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
				int32 prefix = MainTrie.findPrefix(SourceString.begin());
				if(prefix <= 0xff) {
					SourceReader->Back(SourceString.size());
					thisVariable->ElementCount = ElementCount;
					thisVariable->DataCount = 0;
					thisVariable->data = nullptr;
					if(prefix == Instruction&&MultiPart) {
						IsFirstVariable = false;
						thisVariable->next = new Variable();
						thisVariable = thisVariable->next;
						continue;
					}
					thisVariable->next = nullptr;
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
				thisVariable->ElementCount = ElementCount;
				thisVariable->DataCount = 0;
				thisVariable->data = nullptr;
				thisVariable->next = nullptr;
				return;
			}
			printf("error");
			_getch();
			exit(0);
		}
		uint64 tempPointer = SourceReader->Pointer;
		uint32 DataCount = 0;

		for(char Separator;;) {
			check();
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
				thisVariable->ElementCount = ElementCount;
				thisVariable->DataCount = 0;
				thisVariable->data = nullptr;
				thisVariable->next = nullptr;
			} else if(!SourceString.IsEmpty() && Separator) {
				if(DataType > type) {
					printf("Too many data");
					_getch();
					exit(0);
				}
				thisVariable->ElementCount = (ElementCount) ? ElementCount : 1;
				thisVariable->DataCount = 1;
				thisVariable->next = nullptr;
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
					thisVariable->data = allocByType(type, 1);
					assignByType(thisVariable->data, 0, type, 0);
					assignByType(thisVariable->data, value, DataType, 0);
				}
			} else {
				printf("error");
				_getch();
				exit(0);
			}
			if(MultiPart) {
				checkIgnEOT();
				SourceReader->GetWord(SourceString);
				if(SourceString.IsEmpty()) {
					return;
				} else if(Instruction == 0xD0) {
					if(SourceString[0] != 'r' || SourceString[1] != 'a' || SourceString[2] != 'm') {
						return;
					}
				} else {
					if(SourceString[0] != 'r' || SourceString[1] != 'a' || SourceString[2] != 'm') {
						return;
					}
				}
				IsFirstVariable = false;
				thisVariable->next = new Variable();
				thisVariable = thisVariable->next;
				continue;
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

		thisVariable->data = allocByType(type, TrueDataCount);
		assignByType(thisVariable->data, 0ll, type, TrueDataCount - 1);
		thisVariable->ElementCount = ElementCount;
		thisVariable->DataCount = TrueDataCount;
		thisVariable->next = nullptr;

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
				assignByType(thisVariable->data, value, DataType, DataIndex);
				if(Separator != ',')break;
			}
		}
		if(!MultiPart)return;
		checkIgnEOT();
		SourceReader->GetWord(SourceString);
		if(SourceString.IsEmpty()) {
			return;
		} else if(Instruction == 0xD0) {
			if(SourceString[0] != 'r' || SourceString[1] != 'a' || SourceString[2] != 'm') {
				return;
			}
		} else {
			if(SourceString[0] != 'r' || SourceString[1] != 'a' || SourceString[2] != 'm') {
				return;
			}
		}
		IsFirstVariable = false;
		thisVariable->next = new Variable();
		thisVariable = thisVariable->next;
	} while(MultiPart);
}