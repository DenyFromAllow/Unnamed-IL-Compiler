#include "../simple.h"

//构造函数

SIMPLE_STRING::SIMPLE_STRING(const char *InChar) {
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) Simple_MemFindb(InChar, 0)) * 2 / 10) + MemLength) + First + 1];
	Simple_MemMovs(begin(), InChar, size());
	StringPointer[Last] = 0;
}

SIMPLE_STRING::SIMPLE_STRING(const char * InChar, const uint32 count) {
	StringPointer = new char[MemLength = (Last = (First = (MemLength = count) * 2 / 10) + MemLength) + First + 1];
	Simple_MemMovs(begin(), InChar, size());
	StringPointer[Last] = 0;
}

SIMPLE_STRING::SIMPLE_STRING(const char InChar) {
	MemLength = 2; First = 0; Last = 1;
	StringPointer = new char[2]{ InChar, 0 };
}

SIMPLE_STRING::SIMPLE_STRING(const SIMPLE_STRING &InString) {
	StringPointer = new char[MemLength = (Last = (First = (MemLength = InString.size()) * 2 / 10) + MemLength) + First + 1];
	Simple_MemMovs(begin(), InString.begin(), size());
	StringPointer[Last] = 0;
}

SIMPLE_STRING::SIMPLE_STRING(SIMPLE_STRING &&InString) {
	StringPointer = InString.StringPointer;
	First = InString.First, Last = InString.Last, MemLength = InString.MemLength;
	InString.StringPointer = nullptr;
	InString.First = 0, InString.Last = 0, InString.MemLength = 0;
}

SIMPLE_STRING::SIMPLE_STRING(const std::string &InStdString) {
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) InStdString.size()) * 2 / 10) + MemLength) + First + 1];
	Simple_MemMovs(begin(), InStdString.begin()._Ptr, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const int32 &In) {
	char buffer[12];
	SimpleTP_Int32ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) Simple_MemFindb(buffer, 0)) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const int64 &In) {
	char buffer[21];
	SimpleTP_Int64ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) Simple_MemFindb(buffer, 0)) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const uint32 &In) {
	char buffer[11];
	SimpleTP_Uint32ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) Simple_MemFindb(buffer, 0)) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const uint64 &In) {
	char buffer[21];
	SimpleTP_Uint64ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) Simple_MemFindb(buffer, 0)) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const int &In) {
	char buffer[12];
	SimpleTP_Int32ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) Simple_MemFindb(buffer, 0)) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const unsigned int	&In) {
	char buffer[11];
	SimpleTP_Uint32ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) Simple_MemFindb(buffer, 0)) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const float &In) {
	char buffer[12];
	SimpleTP_FloatToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) Simple_MemFindb(buffer, 0)) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const double &In) {
	char buffer[22];
	SimpleTP_DoubleToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) Simple_MemFindb(buffer, 0)) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}

SIMPLE_STRING::SIMPLE_STRING(const SIMPLE_TIME & In) {
	char buffer[25];
	SimpleTP_TimeToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (In.us < 0) ? 24 : 23) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}

SIMPLE_STRING::SIMPLE_STRING(const uint8 InLength, const int32 & In) {
	char buffer[257];
	SimpleTP_Int32ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) (In < 0) ? InLength + 1 : InLength) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const uint8 InLength, const int64 & In) {
	char buffer[257];
	SimpleTP_Int64ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) (In < 0) ? InLength + 1 : InLength) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const uint8 InLength, const uint32 & In) {
	char buffer[256];
	SimpleTP_Uint32ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) InLength) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const uint8 InLength, const uint64 & In) {
	char buffer[256];
	SimpleTP_Uint64ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) InLength) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const uint8 InLength, const int &In) {
	char buffer[257];
	SimpleTP_Int32ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) (In < 0) ? InLength + 1 : InLength) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}
SIMPLE_STRING::SIMPLE_STRING(const uint8 InLength, const unsigned int &In) {
	char buffer[256];
	SimpleTP_Uint32ToString (buffer, In);
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) InLength) / 5) + MemLength) + First + 1];
	Simple_MemMovs(begin(), buffer, size());
	StringPointer[Last] = 0;
}

//赋值操作

SIMPLE_STRING &SIMPLE_STRING::operator=(const char *In) {
	if(StringPointer)delete[]StringPointer;
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) Simple_MemFindb(In, 0)) * 2 / 10) + MemLength) + First + 1];
	Simple_MemMovs(begin(), In, size());
	StringPointer[Last] = 0;
	return *this;
}
SIMPLE_STRING &SIMPLE_STRING::operator=(const SIMPLE_STRING &In) {
	if(StringPointer)delete[]StringPointer;
	StringPointer = new char[MemLength = (Last = (First = (MemLength = In.size()) * 2 / 10) + MemLength) + First + 1];
	Simple_MemMovs(begin(), In.begin(), size());
	StringPointer[Last] = 0;
	return *this;
}
SIMPLE_STRING &SIMPLE_STRING::operator=(SIMPLE_STRING && In) {
	clear();
	StringPointer = In.StringPointer;
	First = In.First, Last = In.Last, MemLength = In.MemLength;
	In.StringPointer = nullptr;
	In.First = 0, In.Last = 0, In.MemLength = 0;
	return *this;
}
SIMPLE_STRING &SIMPLE_STRING::operator=(const std::string &In) {
	if(StringPointer)delete[]StringPointer;
	StringPointer = new char[MemLength = (Last = (First = (MemLength = (int32)In.size()) * 2 / 10) + MemLength) + First + 1];
	Simple_MemMovs(begin(), In.begin()._Ptr, size());
	StringPointer[Last] = 0;
	return *this;
}

bool SIMPLE_STRING::operator==(const char * In) const {
	if(!StringPointer || !MemLength || Last <= First) {
		if(In == nullptr || *In == 0)return true;
		else return false;
	}
	const char *ptr = begin();
	while(*ptr&&*ptr == *In) ptr++, In++;
	return *In == *ptr;
}
bool SIMPLE_STRING::operator==(const SIMPLE_STRING &In) const {
	if(!StringPointer || !MemLength || Last <= First) {
		if(!In.StringPointer || !In.MemLength || In.Last <= In.First) return true;
		else return false;
	}
	const char *ptr = begin();
	const char *InPtr = In.begin();
	while(*ptr&&*ptr == *InPtr) ptr++, InPtr++;
	return *InPtr == *ptr;
}
bool SIMPLE_STRING::operator==(const std::string &In) const {
	if(!StringPointer || !MemLength || Last <= First) {
		if(In.empty()) return true;
		else return false;
	}
	const char *ptr = begin();
	const char *InPtr = In.begin()._Ptr;
	while(*ptr&&*ptr == *InPtr) ptr++, InPtr++;
	return *InPtr == *ptr;
}

SIMPLE_STRING::operator std::string() {
	if(!StringPointer || !MemLength || Last <= First)return std::string();
	StringPointer[Last] = 0;
	return std::string(begin());
}

SIMPLE_STRING & print(SIMPLE_STRING &InString) {
	InString++;
	return InString;
}
SIMPLE_STRING & flush(SIMPLE_STRING &InString) {
	InString++;
	~InString;
	return InString;
}
SIMPLE_STRING & clear(SIMPLE_STRING & InString) {
	~InString;
	return InString;
}
SIMPLE_STRING & endl(SIMPLE_STRING & InString) {
	InString << '\n';
	return InString;
}
SIMPLE_STRING & end(SIMPLE_STRING & InString) {
	if(InString.StringPointer && InString.MemLength && InString.Last > InString.First) printf("%s\n", InString.begin());
	~InString;
	return InString;
}
