#pragma once

class  SIMPLE_UNSIGNEDINTEGER128 {
public:
	union {
		struct { unsigned long long HighPart, LowPart; };
		unsigned long long Data[2];
	};
	FORCEINLINE SIMPLE_UNSIGNEDINTEGER128() : HighPart(0),LowPart(0) { }
	FORCEINLINE SIMPLE_UNSIGNEDINTEGER128(unsigned long long In0, unsigned long long In1) : HighPart(In0), LowPart(In1) { }
	FORCEINLINE SIMPLE_UNSIGNEDINTEGER128(unsigned long long In) : HighPart(0), LowPart(In) { }

	FORCEINLINE SIMPLE_UNSIGNEDINTEGER128 operator=(SIMPLE_UNSIGNEDINTEGER128 in) { Data[0] = in.Data[0]; Data[1] = in.Data[1]; return *this; }
	FORCEINLINE SIMPLE_UNSIGNEDINTEGER128 operator=(unsigned long long in) { Data[1] = in; return *this; }
	FORCEINLINE SIMPLE_UNSIGNEDINTEGER128 operator=(unsigned int in) { Data[1] = in; return *this; }

	SIMPLE_UNSIGNEDINTEGER128 operator+(SIMPLE_UNSIGNEDINTEGER128);
	SIMPLE_UNSIGNEDINTEGER128 operator-(SIMPLE_UNSIGNEDINTEGER128);
	SIMPLE_UNSIGNEDINTEGER128 operator*(SIMPLE_UNSIGNEDINTEGER128);
	SIMPLE_UNSIGNEDINTEGER128 operator/(SIMPLE_UNSIGNEDINTEGER128);
	SIMPLE_UNSIGNEDINTEGER128 operator%(SIMPLE_UNSIGNEDINTEGER128);
	SIMPLE_UNSIGNEDINTEGER128 operator+=(SIMPLE_UNSIGNEDINTEGER128);
	SIMPLE_UNSIGNEDINTEGER128 operator-=(SIMPLE_UNSIGNEDINTEGER128);
	SIMPLE_UNSIGNEDINTEGER128 operator*=(SIMPLE_UNSIGNEDINTEGER128);
	SIMPLE_UNSIGNEDINTEGER128 operator/=(SIMPLE_UNSIGNEDINTEGER128);
	SIMPLE_UNSIGNEDINTEGER128 operator%=(SIMPLE_UNSIGNEDINTEGER128);
	bool operator>>(unsigned char);
	bool operator<<(unsigned char);
	bool operator>>=(unsigned char);
	bool operator<<=(unsigned char);
	bool operator>(SIMPLE_UNSIGNEDINTEGER128);
	bool operator<(SIMPLE_UNSIGNEDINTEGER128);
	bool operator==(SIMPLE_UNSIGNEDINTEGER128 in) { return Data[0] == in.Data[0] && Data[1] == in.Data[1]; }
	bool operator>=(SIMPLE_UNSIGNEDINTEGER128);
	bool operator<=(SIMPLE_UNSIGNEDINTEGER128);
	bool operator!=(SIMPLE_UNSIGNEDINTEGER128);
	SIMPLE_UNSIGNEDINTEGER128 operator++();
	const SIMPLE_UNSIGNEDINTEGER128 operator++(int);
	SIMPLE_UNSIGNEDINTEGER128 operator--();
	const SIMPLE_UNSIGNEDINTEGER128 operator--(int);
};