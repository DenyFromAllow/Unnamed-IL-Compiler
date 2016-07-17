#include "../simple.h"

//缓冲区容量至少5字节
void SimpleTP_Int8ToString(char * buffer, int8 InInt8) {
	bool IsPositive = true;
	if(InInt8 < 0) {
		InInt8 = -InInt8;
		buffer[0] = '-';
		IsPositive = false;
	} else if(InInt8 == 0) {
		buffer[0] = '0';
		buffer[1] = 0;
		return;
	}
	buffer[4] = 0;
	uint8 index;
	for(index = 3; InInt8 > 0; index--) {
		buffer[index] = '0' + InInt8 % 10;
		InInt8 /= 10;
	}
	Simple_MemMoveLowb(buffer + index + 1, 4 - index, IsPositive ? index + 1 : index);
}

//缓冲区容量至少7字节
void SimpleTP_Int16ToString(char * buffer, int16 InInt16) {
	bool IsPositive = true;
	if(InInt16 < 0) {
		InInt16 = -InInt16;
		buffer[0] = '-';
		IsPositive = false;
	} else if(InInt16 == 0) {
		buffer[0] = '0';
		buffer[1] = 0;
		return;
	}
	buffer[6] = 0;
	uint8 index;
	for(index = 5; InInt16 > 0; index--) {
		buffer[index] = '0' + InInt16 % 10;
		InInt16 /= 10;
	}
	Simple_MemMoveLowb(buffer + index + 1, 6 - index, IsPositive ? index + 1 : index);
}

//缓冲区容量至少12字节
void SimpleTP_Int32ToString(char * buffer, int32 InInt32) {
	bool IsPositive = true;
	if(InInt32 < 0) {
		InInt32 = -InInt32;
		buffer[0] = '-';
		IsPositive = false;
	} else if(InInt32 == 0) {
		buffer[0] = '0';
		buffer[1] = 0;
		return;
	}
	buffer[11] = 0;
	uint8 index;
	for(index = 10; InInt32 > 0; index--) {
		buffer[index] = '0' + InInt32 % 10;
		InInt32 /= 10;
	}
	Simple_MemMoveLowb(buffer + index + 1, 11 - index, IsPositive ? index + 1 : index);
}

//缓冲区容量至少21字节
void SimpleTP_Int64ToString(char * buffer, int64 InInt64) {
	bool IsPositive = true;
	if(InInt64 < 0) {
		InInt64 = -InInt64;
		buffer[0] = '-';
		IsPositive = false;
	} else if(InInt64 == 0) {
		buffer[0] = '0';
		buffer[1] = 0;
		return;
	}
	buffer[20] = 0;
	uint8 index;
	for(index = 19; InInt64 > 0; index--) {
		buffer[index] = '0' + InInt64 % 10;
		InInt64 /= 10;
	}
	Simple_MemMoveLowb(buffer + index + 1, 20 - index, IsPositive ? index + 1 : index);
}

//缓冲区容量至少4字节
void SimpleTP_Uint8ToString(char * buffer, uint8 InInt8) {
	if(InInt8 == 0) {
		buffer[0] = '0';
		buffer[1] = 0;
		return;
	}
	buffer[3] = 0;
	int8 index;
	for(index = 2; InInt8 > 0; index--) {
		buffer[index] = '0' + InInt8 % 10;
		InInt8 /= 10;
	}
	Simple_MemMoveLowb(buffer + index + 1, 3 - index, index + 1);
}

//缓冲区容量至少6字节
void SimpleTP_Uint16ToString(char * buffer, uint16 InInt16) {
	if(InInt16 == 0) {
		buffer[0] = '0';
		buffer[1] = 0;
		return;
	}
	buffer[5] = 0;
	int8 index;
	for(index = 4; InInt16 > 0; index--) {
		buffer[index] = '0' + InInt16 % 10;
		InInt16 /= 10;
	}
	Simple_MemMoveLowb(buffer + index + 1, 5 - index, index + 1);
}

//缓冲区容量至少11字节
void SimpleTP_Uint32ToString(char * buffer, uint32 InInt32) {
	if(InInt32 == 0) {
		buffer[0] = '0';
		buffer[1] = 0;
		return;
	}
	buffer[10] = 0;
	int8 index;
	for(index = 9; InInt32 > 0; index--) {
		buffer[index] = '0' + InInt32 % 10;
		InInt32 /= 10;
	}
	Simple_MemMoveLowb(buffer + index + 1, 10 - index, index + 1);
}

//缓冲区容量至少21字节
void SimpleTP_Uint64ToString(char * buffer, uint64 InInt64) {
	if(InInt64 == 0) {
		buffer[0] = '0';
		buffer[1] = 0;
		return;
	}
	buffer[20] = 0;
	int8 index;
	for(index = 19; InInt64 > 0; index--) {
		buffer[index] = '0' + InInt64 % 10;
		InInt64 /= 10;
	}
	Simple_MemMoveLowb(buffer + index + 1, 20 - index, index + 1);
}

//缓冲区容量至少12字节
void SimpleTP_FloatToString(char * string, float InFloat) {
	char buffer[32];
	bool IsPositive = true;
	int16 e;
	if(InFloat < 0) {
		InFloat = -InFloat;
		IsPositive = false;
		string[0] = '-';
		string[11] = 0;
	} else if(InFloat == 0) {
		string[0] = '0'; string[1] = '.'; string[2] = '0'; string[3] = '0'; string[4] = '0'; string[5] = '0'; string[6] = '0'; string[7] = '0'; string[8] = '0'; string[9] = '0'; string[10] = 0;
		return;
	} else {
		string[10] = 0;
	}
	if(InFloat <= 1e-5f) {
		string[0] = 'T'; string[1] = 'O'; string[2] = 'O'; string[3] = '.'; string[4] = 'S'; string[5] = 'M'; string[6] = 'A'; string[7] = 'L'; string[8] = 'L'; string[9] = '.'; string[10] = 0;
		return;
	} else if(InFloat >= 1e8f) {
		string[0] = 'T'; string[1] = 'O'; string[2] = 'O'; string[3] = '.'; string[4] = 'B'; string[5] = 'I'; string[6] = 'G'; string[7] = '.'; string[8] = '.'; string[9] = '.'; string[10] = 0;
		return;
	} else {
		SimpleTP_Int32ToString(buffer, (int32) InFloat);
		int8 index = (int8)Simple_MemFindb(buffer, 0);
		buffer[index++] = '.';
		InFloat -= (int32) InFloat;
		for(int32 multiple = 10; index < 10; index++, multiple *= 10) {
			buffer[index] = '0' + (int32) (InFloat * multiple) % 10;
		}
		Simple_MemMovs(IsPositive ? string : string + 1, buffer, 10);
	}
}

//缓冲区容量至少22字节
void SimpleTP_DoubleToString(char * string, double InDouble) {
	char buffer[64];
	bool IsPositive = true;
	int16 e;
	if(InDouble < 0) {
		InDouble = -InDouble;
		IsPositive = false;
		string[0] = '-';
		string[21] = 0;
	} else if(InDouble == 0) {
		string[0] = '0'; string[1] = '.'; string[2] = '0'; string[3] = '0'; string[4] = '0'; string[5] = '0'; string[6] = '0';
		string[7] = '0'; string[8] = '0'; string[9] = '0'; string[10] = '0'; string[11] = '0'; string[12] = '0'; string[13] = '0';
		string[14] = '0'; string[15] = '0'; string[16] = '0'; string[17] = '0'; string[18] = '0'; string[19] = '0'; string[20] = 0;
		return;
	} else {
		string[20] = 0;
	}
	if(InDouble <= 1e-10) {
		string[0] = 'T'; string[1] = 'O'; string[2] = 'O'; string[3] = '.'; string[4] = 'S'; string[5] = 'M'; string[6] = 'A';
		string[7] = 'L'; string[8] = 'L'; string[9] = '.'; string[10] = 'T'; string[11] = 'O'; string[12] = 'O'; string[13] = '.';
		string[14] = 'S'; string[15] = 'M'; string[16] = 'A'; string[17] = 'L'; string[18] = 'L'; string[19] = '.'; string[20] = 0;
		return;
	} else if(InDouble >= 1e15) {
		string[0] = 'T'; string[1] = 'O'; string[2] = 'O'; string[3] = '.'; string[4] = 'B'; string[5] = 'I'; string[6] = 'G';
		string[7] = '.'; string[8] = 'T'; string[9] = 'O'; string[10] = 'O'; string[11] = '.'; string[12] = 'B'; string[13] = 'I';
		string[14] = 'G'; string[15] = '.'; string[16] = 'T'; string[17] = 'O'; string[18] = 'O'; string[19] = '.'; string[20] = 0;
		return;
	} else {
		SimpleTP_Int64ToString(buffer, (int64) InDouble);
		int8 index = (int8) Simple_MemFindb(buffer, 0);
		buffer[index++] = '.';
		InDouble -= (int64) InDouble;
		for(int64 multiple = 10; index < 20; index++, multiple *= 10) {
			buffer[index] = '0' + (int64) (InDouble * multiple) % 10;
		}
		Simple_MemMovs(IsPositive ? string : string + 1, buffer, 20);
	}
}

//缓冲区>=25
void SimpleTP_TimeToString(char * string, SIMPLE_TIME InTime) {
	bool IsPositive = true;
	if(InTime.us < 0) {
		InTime = -InTime;
		IsPositive = false;
		string[0] = '-';
		string++;
	}
	string[23] = 0;
	string[22] = '0' + InTime.us % 10; InTime.us /= 10;
	string[21] = '0' + InTime.us % 10; InTime.us /= 10;
	string[20] = '0' + InTime.us % 10; InTime.us /= 10;
	string[19] = '0' + InTime.us % 10; InTime.us /= 10;
	string[18] = '0' + InTime.us % 10; InTime.us /= 10;
	string[17] = '0' + InTime.us % 10; InTime.us /= 10;
	string[16] = '.';
	string[15] = '0' + InTime.us % 10; InTime.us /= 10;
	string[14] = '0' + InTime.us % 6; InTime.us /= 6;
	string[13] = ':';
	string[12] = '0' + InTime.us % 10; InTime.us /= 10;
	string[11] = '0' + InTime.us % 6; InTime.us /= 6;
	string[10] = ':';
	string[9] = '0' + InTime.us % 24 % 10;
	string[8] = '0' + InTime.us % 24 / 10; InTime.us /= 24;
	string[7] = ' ';
	string[6] = 'y';
	string[5] = 'a';
	string[4] = 'd';
	string[3] = '0' + InTime.us % 10; InTime.us /= 10;
	string[2] = '0' + InTime.us % 10; InTime.us /= 10;
	string[1] = '0' + InTime.us % 10; InTime.us /= 10;
	string[0] = '0' + InTime.us % 10; InTime.us /= 10;
	if(!IsPositive)string--;
}

//缓冲区>=InLength+2
void SimpleTP_Int8ToString (char * buffer, uint8 InLength, int8 InInt8) {
	if(InLength == 0) {
		buffer[0] = 0;
		return;
	}
	uint8 first = 0;
	if(InInt8 < 0) {
		InInt8 = -InInt8;
		buffer[0] = '-';
		first = 1;
	} else {
		first = 0;
	}
	buffer[InLength + first] = 0;
	uint8 index;
	for(index = InLength - 1; InInt8 > 0; index--) {
		buffer[index] = '0' + InInt8 % 10;
		InInt8 /= 10;
		if(index == first)return;
	}
	for(;; index--) {
		buffer[index] = '0';
		if(index == first)return;
	}
}
//缓冲区>=InLength+2
void SimpleTP_Int16ToString (char * buffer, uint8 InLength, int16 InInt16) {
	if(InLength == 0) {
		buffer[0] = 0;
		return;
	}
	uint8 first = 0;
	if(InInt16 < 0) {
		InInt16 = -InInt16;
		buffer[0] = '-';
		first = 1;
	} else {
		first = 0;
	}
	buffer[InLength + first] = 0;
	uint8 index;
	for(index = InLength - 1; InInt16 > 0; index--) {
		buffer[index] = '0' + InInt16 % 10;
		InInt16 /= 10;
		if(index == first)return;
	}
	for(;; index--) {
		buffer[index] = '0';
		if(index == first)return;
	}
}
//缓冲区>=InLength+2
void SimpleTP_Int32ToString (char * buffer, uint8 InLength, int32 InInt32) {
	if(InLength == 0) {
		buffer[0] = 0;
		return;
	}
	uint8 first;
	if(InInt32 < 0) {
		InInt32 = -InInt32;
		buffer[0] = '-';
		first = 1;
	} else {
		first = 0;
	}
	buffer[InLength + first] = 0;
	uint8 index;
	for(index = InLength - 1; InInt32 > 0; index--) {
		buffer[index] = '0' + InInt32 % 10;
		InInt32 /= 10;
		if(index == first)return;
	}
	for(;; index--) {
		buffer[index] = '0';
		if(index == first)return;
	}
}
//缓冲区>=InLength+2
void SimpleTP_Int64ToString (char * buffer, uint8 InLength, int64 InInt64) {
	if(InLength == 0) {
		buffer[0] = 0;
		return;
	}
	uint8 first = 0;
	if(InInt64 < 0) {
		InInt64 = -InInt64;
		buffer[0] = '-';
		first = 1;
	} else {
		first = 0;
	}
	buffer[InLength + first] = 0;
	uint8 index;
	for(index = InLength - 1; InInt64 > 0; index--) {
		buffer[index] = '0' + InInt64 % 10;
		InInt64 /= 10;
		if(index == first)return;
	}
	for(;; index--) {
		buffer[index] = '0';
		if(index == first)return;
	}
}
//缓冲区>=InLength+1
void SimpleTP_Uint8ToString (char * buffer, uint8 InLength, uint8 InInt8) {
	if(InLength == 0) {
		buffer[0] = 0;
		return;
	}
	buffer[InLength] = 0;
	uint8 index;
	for(index = InLength - 1; InInt8 > 0; index--) {
		buffer[index] = '0' + InInt8 % 10;
		InInt8 /= 10;
		if(index == 0)return;
	}
	for(;; index--) {
		buffer[index] = '0';
		if(index == 0)return;
	}
}
//缓冲区>=InLength+1
void SimpleTP_Uint16ToString (char * buffer, uint8 InLength, uint16 InInt16) {
	if(InLength == 0) {
		buffer[0] = 0;
		return;
	}
	buffer[InLength] = 0;
	uint8 index;
	for(index = InLength - 1; InInt16 > 0; index--) {
		buffer[index] = '0' + InInt16 % 10;
		InInt16 /= 10;
		if(index == 0)return;
	}
	for(;; index--) {
		buffer[index] = '0';
		if(index == 0)return;
	}
}
//缓冲区>=InLength+1
void SimpleTP_Uint32ToString (char * buffer, uint8 InLength, uint32 InInt32) {
	if(InLength == 0) {
		buffer[0] = 0;
		return;
	}
	buffer[InLength] = 0;
	uint8 index;
	for(index = InLength - 1; InInt32 > 0; index--) {
		buffer[index] = '0' + InInt32 % 10;
		InInt32 /= 10;
		if(index == 0)return;
	}
	for(;; index--) {
		buffer[index] = '0';
		if(index == 0)return;
	}
}
//缓冲区>=InLength+1
void SimpleTP_Uint64ToString (char * buffer, uint8 InLength, uint64 InInt64) {
	if(InLength == 0) {
		buffer[0] = 0;
		return;
	}
	buffer[InLength] = 0;
	uint8 index;
	for(index = InLength - 1; InInt64 > 0; index--) {
		buffer[index] = '0' + InInt64 % 10;
		InInt64 /= 10;
		if(index == 0)return;
	}
	for(;; index--) {
		buffer[index] = '0';
		if(index == 0)return;
	}
}

bool SIMPLE_STRING::OCTToint32(int32 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	char*ReadingChar = begin();
	bool IsNeg = false;
	if(*ReadingChar == '-') {
		ReadingChar++;
		if(ReadingChar >= end())return false;
		IsNeg = true;
	}
	for(; ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar<'0' || *ReadingChar>'7') {
			Out = 0;
			return false;
		}
		Out *= 8;
		Out += *ReadingChar - '0';
	}
	if(IsNeg) {
		Out = -Out;
	}
	return true;
}

bool SIMPLE_STRING::DECToint32(int32 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	char*ReadingChar = begin();
	bool IsNeg = false;
	if(*ReadingChar == '-') {
		ReadingChar++;
		if(ReadingChar >= end())return false;
		IsNeg = true;
	}
	for(; ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar<'0' || *ReadingChar>'9') {
			Out = 0;
			return false;
		}
		Out *= 10;
		Out += *ReadingChar - '0';
	}
	if(IsNeg) {
		Out = -Out;
	}
	return true;
}

bool SIMPLE_STRING::HEXToint32(int32 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	char*ReadingChar = begin();
	bool IsNeg = false;
	if(*ReadingChar == '-') {
		ReadingChar++;
		IsNeg = true;
	}
	if(*ReadingChar == '0'&&*(ReadingChar + 1) == 'x') {
		ReadingChar += 2;
	}
	if(ReadingChar >= end())return false;
	for(; ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar >= '0' && *ReadingChar <= '9') {
			Out *= 16;
			Out += *ReadingChar - '0';
		} else if(*ReadingChar >= 'a' && *ReadingChar <= 'f') {
			Out *= 16;
			Out += *ReadingChar - ('a' - 10);
		} else if(*ReadingChar >= 'A' && *ReadingChar <= 'F') {
			Out *= 16;
			Out += *ReadingChar - ('A' - 10);
		} else if((*ReadingChar == 'h' || *ReadingChar == 'H') && ReadingChar + 1 == end()) {
			break;
		} else {
			Out = 0;
			return false;
		}
	}
	if(IsNeg) {
		Out = -Out;
	}
	return true;
}

bool SIMPLE_STRING::OCTTouint32(uint32 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	for(char*ReadingChar = begin(); ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar<'0' || *ReadingChar>'7') {
			Out = 0;
			return false;
		}
		Out *= 8;
		Out += *ReadingChar - '0';
	}
	return true;
}

bool SIMPLE_STRING::DECTouint32(uint32 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	for(char*ReadingChar = begin(); ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar<'0' || *ReadingChar>'9') {
			Out = 0;
			return false;
		}
		Out *= 10;
		Out += *ReadingChar - '0';
	}
	return true;
}

bool SIMPLE_STRING::HEXTouint32(uint32 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	char*ReadingChar = begin();
	if(*ReadingChar == '0'&&*(ReadingChar + 1) == 'x') {
		ReadingChar += 2;
		if(ReadingChar >= end())return false;
	}
	for(; ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar >= '0' && *ReadingChar <= '9') {
			Out *= 16;
			Out += *ReadingChar - '0';
		} else if(*ReadingChar >= 'a' && *ReadingChar <= 'f') {
			Out *= 16;
			Out += *ReadingChar - ('a' - 10);
		} else if(*ReadingChar >= 'A' && *ReadingChar <= 'F') {
			Out *= 16;
			Out += *ReadingChar - ('A' - 10);
		} else if((*ReadingChar == 'h' || *ReadingChar == 'H') && ReadingChar + 1 == end()) {
			break;
		} else {
			Out = 0;
			return false;
		}
	}
	return true;
}

bool SIMPLE_STRING::OCTToint64(int64 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	char*ReadingChar = begin();
	bool IsNeg = false;
	if(*ReadingChar == '-') {
		ReadingChar++;
		if(ReadingChar >= end())return false;
		IsNeg = true;
	}
	for(; ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar<'0' || *ReadingChar>'7') {
			Out = 0;
			return false;
		}
		Out *= 8;
		Out += *ReadingChar - '0';
	}
	if(IsNeg) {
		Out = -Out;
	}
	return true;
}

bool SIMPLE_STRING::DECToint64(int64 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	char*ReadingChar = begin();
	bool IsNeg = false;
	if(*ReadingChar == '-') {
		ReadingChar++;
		if(ReadingChar >= end())return false;
		IsNeg = true;
	}
	for(; ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar<'0' || *ReadingChar>'9') {
			Out = 0;
			return false;
		}
		Out *= 10;
		Out += *ReadingChar - '0';
	}
	if(IsNeg) {
		Out = -Out;
	}
	return true;
}

bool SIMPLE_STRING::HEXToint64(int64 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	char*ReadingChar = begin();
	bool IsNeg = false;
	if(*ReadingChar == '-') {
		ReadingChar++;
		IsNeg = true;
	}
	if(*ReadingChar == '0'&&*(ReadingChar + 1) == 'x') {
		ReadingChar += 2;
	}
	if(ReadingChar >= end())return false;
	for(; ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar >= '0' && *ReadingChar <= '9') {
			Out *= 16;
			Out += *ReadingChar - '0';
		} else if(*ReadingChar >= 'a' && *ReadingChar <= 'f') {
			Out *= 16;
			Out += *ReadingChar - ('a' - 10);
		} else if(*ReadingChar >= 'A' && *ReadingChar <= 'F') {
			Out *= 16;
			Out += *ReadingChar - ('A' - 10);
		} else if((*ReadingChar == 'h' || *ReadingChar == 'H') && ReadingChar + 1 == end()) {
			break;
		} else {
			Out = 0;
			return false;
		}
	}
	if(IsNeg) {
		Out = -Out;
	}
	return true;
}

bool SIMPLE_STRING::OCTTouint64(uint64 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	for(char*ReadingChar = begin(); ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar<'0' || *ReadingChar>'7') {
			Out = 0;
			return false;
		}
		Out *= 8;
		Out += *ReadingChar - '0';
	}
	return true;
}

bool SIMPLE_STRING::DECTouint64(uint64 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	for(char*ReadingChar = begin(); ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar<'0' || *ReadingChar>'9') {
			Out = 0;
			return false;
		}
		Out *= 10;
		Out += *ReadingChar - '0';
	}
	return true;
}

bool SIMPLE_STRING::HEXTouint64(uint64 &Out) {
	Out = 0;
	if(IsEmpty()) return false;
	char*ReadingChar = begin();
	if(*ReadingChar == '0'&&*(ReadingChar + 1) == 'x') {
		ReadingChar += 2;
		if(ReadingChar >= end())return false;
	}
	for(; ReadingChar < end(); ReadingChar++) {
		if(*ReadingChar >= '0' && *ReadingChar <= '9') {
			Out *= 16;
			Out += *ReadingChar - '0';
		} else if(*ReadingChar >= 'a' && *ReadingChar <= 'f') {
			Out *= 16;
			Out += *ReadingChar - ('a' - 10);
		} else if(*ReadingChar >= 'A' && *ReadingChar <= 'F') {
			Out *= 16;
			Out += *ReadingChar - ('A' - 10);
		} else if((*ReadingChar == 'h' || *ReadingChar == 'H') && ReadingChar + 1 == end()) {
			break;
		} else {
			Out = 0;
			return false;
		}
	}
	return true;
}
/*
bool HEXToint32(int32 &Out);
bool OCTTouint32(uint32 &Out);
bool DECTouint32(uint32 &Out);
bool HEXTouint32(uint32 &Out);
bool OCTToint64(int64 &Out);
bool DECToint64(int64 &Out);
bool HEXToint64(int64 &Out);
bool OCTTouint64(int64 &Out);
bool DECTouint64(int64 &Out);
bool HEXTouint64(int64 &Out);*/