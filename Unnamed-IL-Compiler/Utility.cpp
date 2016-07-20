#include "main.h"

bool check() {
	bool NextLine = false;
	while(1) {
		SourceReader->SkipIgnoreChar();
		if(SourceReader->GetChar() == '\n') {
			SourceReader->Forward(); NextLine = true;
		} else if(SourceReader->GetChar() == '/') {
			SourceReader->Forward();
			if(SourceReader->GetChar() == '/') {
				SourceReader->SkipLine();
				NextLine = true;
			} else {
				printf("/");
				_getch();
				exit(0);
			}
		} else if(SourceReader->EndOfText()) {
			printf("EndOfText");
			_getch();
			exit(0);
		} else {
			return NextLine;
		}
	}
}

VarType getType(String SourceString, uint32 Start) {
	if(SourceString[Start] == '8'&& SourceString[Start + 1] == 0) {
		return VarType::i8;
	} else if(SourceString[Start] == '1'&& SourceString[Start + 1] == '6'&& SourceString[Start + 2] == 0) {
		return VarType::i16;
	} else if(SourceString[Start] == '3'&& SourceString[Start + 1] == '2'&& SourceString[Start + 2] == 0) {
		return VarType::i32;
	} else if(SourceString[Start] == '6'&& SourceString[Start + 1] == '4'&& SourceString[Start + 2] == 0) {
		return VarType::i64;
	} else if(SourceString[Start] == '1'&& SourceString[Start + 1] == '2'&& SourceString[Start + 2] == '8'&& SourceString[Start + 3] == 0) {
		return VarType::i128;
	} else if(SourceString[Start] == '2'&& SourceString[Start + 1] == '5'&& SourceString[Start + 2] == '6'&& SourceString[Start + 3] == 0) {
		return VarType::i256;
	} else if(SourceString[Start] == 'b'&& SourceString[Start + 1] == 0) {
		return VarType::b;
	} else if(SourceString[Start] == 'w'&& SourceString[Start + 1] == 0) {
		return VarType::w;
	} else if(SourceString[Start] == 'd'&& SourceString[Start + 1] == 0) {
		return VarType::d;
	} else if(SourceString[Start] == 'q'&& SourceString[Start + 1] == 0) {
		return VarType::q;
	} else if(SourceString[Start] == 'f'&& SourceString[Start + 1] == 0) {
		return VarType::f;
	} else if(SourceString[Start] == 'd'&& SourceString[Start + 1] == 'f'&& SourceString[Start + 2] == 0) {
		return VarType::df;
	} else if(SourceString[Start] == 'l'&& SourceString[Start + 1] == 'd'&& SourceString[Start + 2] == 0) {
		return VarType::ld;
	} else if(SourceString[Start] == 'p'&& SourceString[Start + 1] == 't'&& SourceString[Start + 2] == 'r'&& SourceString[Start + 3] == 0) {
		return VarType::ptr;
	} else if(SourceString[Start] == 0) {
		return VarType::none;
	} else {
		return VarType::error;
	}
}

void* allocByType(VarType type, uint32 count) {
	switch(type) {
		case VarType::i8:
			return (void*)new uint8[count];
		case VarType::i16:
			return (void*)new uint16[count];
		case VarType::i32:
			return (void*)new uint32[count];
		case VarType::i64:
			return (void*)new uint64[count];
		case VarType::i128:
			return (void*)new uint128[count];
		case VarType::i256:
			return (void*)new uint256[count];
		default:
			printf("error");
			_getch();
			exit(0);
	}
}

void assignByType(void* pointer,uint64 value,VarType type, uint32 index) {
	switch(type) {
		case VarType::i8:
			((uint8*) pointer)[index] = (uint8) value;
			break;
		case VarType::i16:
			((uint16*) pointer)[index] = (uint16) value;
			break;
		case VarType::i32:
		case VarType::f:
			((uint32*) pointer)[index] = (uint32) value;
			break;
		case VarType::i64:
		case VarType::df:
			((uint64*) pointer)[index] = value;
			break;
		case VarType::i128:
		case VarType::ld:
			((uint128*) pointer)[index][0] = value;
			break;
		case VarType::i256:
			((uint256*) pointer)[index][0] = value;
			break;
		default:
			printf("error");
			_getch();
			exit(0);
	}
}