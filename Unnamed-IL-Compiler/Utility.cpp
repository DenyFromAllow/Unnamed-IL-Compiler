#include "main.h"

bool check() {
	bool NextLine = false;
	while(1) {
		SourceReader->SkipIgnoreChar();
		if(SourceReader->GetChar() == '\r') {
			SourceReader->Forward();
			if(SourceReader->GetChar() == '\n')SourceReader->Forward();
			NextLine = true;
		} else if(SourceReader->GetChar() == '\n') {
			SourceReader->Forward(); NextLine = true;
		} else if(SourceReader->GetChar() == '/') {
			SourceReader->Forward();
			if(SourceReader->GetChar() == '/') {
				SourceReader->SkipLine();
				SourceReader->Forward();
				NextLine = true;
			} else if(SourceReader->GetChar() == '*') {
				while(1) {
					SourceReader->SkipUntil('*');
					SourceReader->Forward();
					if(SourceReader->GetChar() == '/')break;
				}
			} else {
				throw(ILCException(ILCException::UnexpectedSeparator,'/'));
			}
		} else if(SourceReader->GetChar() == ';') {
			throw(ILCException(ILCException::EndOfCommand));
		} else if(SourceReader->EndOfText()) {
			throw(ILCException(ILCException::EndOfText));
		} else {
			return NextLine;
		}
	}
}

uint32 ReadType(String SourceString) {
	if(!SourceString)return VarType::null;
	uint32 type = TypeTrie.find(SourceString.begin());
	if(type)return type;
	if(SourceString.size() < 4)return VarType::null;
	char endChar = *(SourceString.end() - 1);
	if(endChar>='2'&&endChar<='4') {
		uint8 components = endChar - '0';
		if(*(SourceString.end() - 2) == 'v') {
			SourceString.PopBack(2);
			type = TypeTrie.find(SourceString.begin());
			if(type&&type < 0x0F) {
				return type&((components - 1) << 4);
			}
			return VarType::null;
		}
		if(SourceString.size()==5&&SourceString[1] == 'v'&&SourceString[2] == 'e'&&SourceString[3] == 'c') {
			switch(SourceString[0]) {
				case 'b':type = VarType::b; break;
				case 'w':type = VarType::w; break;
				case 'd':type = VarType::d; break;
				case 'q':type = VarType::q; break;
				case 'f':type = VarType::f; break;
				case 'l':type = VarType::df; break;
			}
		} else if(SourceString.size() == 6 && SourceString[2] == 'v'&&SourceString[3] == 'e'&&SourceString[4] == 'c') {
			if(SourceString[2] == 'd'&&SourceString[3] == 'f')type = VarType::df;
			else if(SourceString[2] == 'l'&&SourceString[3] == 'd')type = VarType::ld;
		} else {
			return VarType::null;
		}
		return type&((components - 1) << 4);
	}
	return VarType::null;
}

void* allocByType(uint32 type, uint32 count) {
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

void assignByType(void* pointer,uint64 value, uint32 type, uint32 index) {
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