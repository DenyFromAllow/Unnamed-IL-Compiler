#include "../simple.h"

SIMPLE_STRING &SIMPLE_STRING::PushBack(const char *In) {
	uint32 InSize = (uint32) Simple_MemFindb(In, 0);
	if(!StringPointer || !MemLength || Last < First) {
		if(StringPointer)delete[]StringPointer;
		StringPointer = new char[MemLength = (Last = (First = InSize * 2 / 10) + InSize) + First + 1];
		Simple_MemMovs(begin(), In, size());
		StringPointer[Last] = 0;
	} else if(Last + InSize < MemLength) {
		Simple_MemMovs(end(), In, InSize);
		Last += InSize;
		StringPointer[Last] = 0;
	} else {
		char *OldStringPointer = StringPointer;
		uint32 OldFirst = First, OldLast = Last;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = size() + InSize) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), OldStringPointer + OldFirst, OldLast - OldFirst);
		Simple_MemMovs(begin() + OldLast - OldFirst, In, InSize);
		StringPointer[Last] = 0;
		delete[]OldStringPointer;
	}
	return *this;
}

SIMPLE_STRING &SIMPLE_STRING::PushFront(const char *In) {
	uint32 InSize = (uint32) Simple_MemFindb(In, 0);
	if(!StringPointer || !MemLength || Last < First) {
		if(StringPointer)delete[]StringPointer;
		StringPointer = new char[MemLength = (Last = (First = InSize * 2 / 10) + InSize) + First + 1];
		Simple_MemMovs(begin(), In, size());
		StringPointer[Last] = 0;
	} else if(InSize <= First) {
		Simple_MemMovs(begin() - InSize, In, InSize);
		First -= InSize;
	} else {
		char *OldStringPointer = StringPointer;
		uint32 OldFirst = First, OldLast = Last;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = size() + InSize) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), In, InSize);
		Simple_MemMovs(begin() + InSize, OldStringPointer + OldFirst, OldLast - OldFirst);
		StringPointer[Last] = 0;
		delete[]OldStringPointer;
	}
	return *this;
}

SIMPLE_STRING & SIMPLE_STRING::PushBack(const char * In, const uint32 count) {
	if(!StringPointer || !MemLength || Last < First) {
		if(StringPointer)delete[]StringPointer;
		StringPointer = new char[MemLength = (Last = (First = count * 2 / 10) + count) + First + 1];
		Simple_MemMovs(begin(), In, size());
		StringPointer[Last] = 0;
	} else if(Last + count < MemLength) {
		Simple_MemMovs(end(), In, count);
		Last += count;
		StringPointer[Last] = 0;
	} else {
		char *OldStringPointer = StringPointer;
		uint32 OldFirst = First, OldLast = Last;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = size() + count) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), OldStringPointer + OldFirst, OldLast - OldFirst);
		Simple_MemMovs(begin() + OldLast - OldFirst, In, count);
		StringPointer[Last] = 0;
		delete[]OldStringPointer;
	}
	return *this;
}

SIMPLE_STRING &SIMPLE_STRING::PushFront(const char *In, const uint32 count) {
	if(!StringPointer || !MemLength || Last < First) {
		if(StringPointer)delete[]StringPointer;
		StringPointer = new char[MemLength = (Last = (First = count * 2 / 10) + count) + First + 1];
		Simple_MemMovs(begin(), In, size());
		StringPointer[Last] = 0;
	} else if(count <= First) {
		Simple_MemMovs(begin() - count, In, count);
		First -= count;
	} else {
		char *OldStringPointer = StringPointer;
		uint32 OldFirst = First, OldLast = Last;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = size() + count) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), In, count);
		Simple_MemMovs(begin() + count, OldStringPointer + OldFirst, OldLast - OldFirst);
		StringPointer[Last] = 0;
		delete[]OldStringPointer;
	}
	return *this;
}

SIMPLE_STRING & SIMPLE_STRING::PushBack(const char In) {
	if(!StringPointer || !MemLength || Last < First) {
		if(StringPointer)delete[]StringPointer;
		First = 0;
		Last = 1;
		StringPointer = new char[MemLength = 2];
		StringPointer[0] = In;
		StringPointer[1] = 0;
	} else if(Last + 1 < MemLength) {
		StringPointer[Last] = In;
		StringPointer[++Last] = 0;
	} else {
		char *OldStringPointer = StringPointer;
		uint32 OldFirst = First, OldLast = Last;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = size() + 1) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), OldStringPointer + OldFirst, OldLast - OldFirst);
		StringPointer[Last - 1] = In;
		StringPointer[Last] = 0;
		delete[]OldStringPointer;
	}
	return *this;
}

SIMPLE_STRING & SIMPLE_STRING::PushFront(const char In) {
	if(!StringPointer || !MemLength || Last < First) {
		if(StringPointer)delete[]StringPointer;
		First = 0;
		Last = 1;
		StringPointer = new char[MemLength = 2];
		StringPointer[0] = In;
		StringPointer[1] = 0;
	} else if(First>=1) {
		StringPointer[--First] = In;
	} else {
		char *OldStringPointer = StringPointer;
		uint32 OldFirst = First, OldLast = Last;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = size() + 1) * 2 / 10) + MemLength) + First + 1];
		StringPointer[First] = In;
		Simple_MemMovs(begin() + 1, OldStringPointer + OldFirst, OldLast - OldFirst);
		StringPointer[Last] = 0;
		delete[]OldStringPointer;
	}
	return *this;
}

SIMPLE_STRING &SIMPLE_STRING::PushBack(const SIMPLE_STRING &In) {
	if(!StringPointer || !MemLength || Last < First) {
		if(StringPointer)delete[]StringPointer;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = In.size()) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), In.begin(), size());
		StringPointer[Last] = 0;
	} else if(Last + In.size() < MemLength) {
		Simple_MemMovs(end(), In.begin(), In.size());
		Last += In.size();
		StringPointer[Last] = 0;
	} else {
		char *OldStringPointer = StringPointer;
		uint32 OldFirst = First, OldLast = Last;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = size() + In.size()) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), OldStringPointer + OldFirst, OldLast - OldFirst);
		Simple_MemMovs(begin() + OldLast - OldFirst, In.begin(), In.size());
		StringPointer[Last] = 0;
		delete[]OldStringPointer;
	}
	return *this;
}

SIMPLE_STRING &SIMPLE_STRING::PushFront(const SIMPLE_STRING &In) {
	if(!StringPointer || !MemLength || Last < First) {
		if(StringPointer)delete[]StringPointer;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = In.size()) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), In.begin(), size());
		StringPointer[Last] = 0;
	} else if(In.size() <= First) {
		Simple_MemMovs(begin() - In.size(), In.begin(), In.size());
		First -= In.size();
	} else {
		char *OldStringPointer = StringPointer;
		uint32 OldFirst = First, OldLast = Last;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = size() + In.size()) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), In.begin(), In.size());
		Simple_MemMovs(begin() + In.size(), OldStringPointer + OldFirst, OldLast - OldFirst);
		StringPointer[Last] = 0;
		delete[]OldStringPointer;
	}
	return *this;
}

SIMPLE_STRING &SIMPLE_STRING::PushBack(const std::string &In) {
	if(!StringPointer || !MemLength || Last < First) {
		if(StringPointer)delete[]StringPointer;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) In.size()) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), In.begin()._Ptr, size());
		StringPointer[Last] = 0;
	} else if(Last + In.size() < MemLength) {
		Simple_MemMovs(end(), In.begin()._Ptr, In.size());
		Last += (uint32) In.size();
		StringPointer[Last] = 0;
	} else {
		char *OldStringPointer = StringPointer;
		uint32 OldFirst = First, OldLast = Last;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = size() + (uint32) In.size()) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), OldStringPointer + OldFirst, OldLast - OldFirst);
		Simple_MemMovs(begin() + OldLast - OldFirst, In.begin()._Ptr, In.size());
		StringPointer[Last] = 0;
		delete[]OldStringPointer;
	}
	return *this;
}

SIMPLE_STRING &SIMPLE_STRING::PushFront(const std::string &In) {
	if(!StringPointer || !MemLength || Last < First) {
		if(StringPointer)delete[]StringPointer;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = (uint32) In.size()) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), In.begin()._Ptr, size());
		StringPointer[Last] = 0;
	} else if(In.size() <= First) {
		Simple_MemMovs(begin() - In.size(), In.begin()._Ptr, In.size());
		First -= (uint32) In.size();
	} else {
		char *OldStringPointer = StringPointer;
		uint32 OldFirst = First, OldLast = Last;
		StringPointer = new char[MemLength = (Last = (First = (MemLength = size() + (uint32) In.size()) * 2 / 10) + MemLength) + First + 1];
		Simple_MemMovs(begin(), In.begin()._Ptr, In.size());
		Simple_MemMovs(begin() + In.size(), OldStringPointer + OldFirst, OldLast - OldFirst);
		StringPointer[Last] = 0;
		delete[]OldStringPointer;
	}
	return *this;
}

char *&operator>>(const SIMPLE_STRING &InString, char *&InChar) {
	uint32 InCharLength = (uint32) Simple_MemFindb(InChar, 0);
	char* TempChar = new char[InCharLength + InString.size() + 1];
	Simple_MemMovs(TempChar, InString.begin(), InString.size());
	Simple_MemMovs(TempChar + InString.size(), InChar, InCharLength);
	TempChar[InCharLength + InString.size()] = 0;
	delete[]InChar;
	InChar = TempChar;
	return InChar;
}

char *&operator<<(char *&InChar, SIMPLE_STRING &InString) {
	uint32 InCharLength = (uint32) Simple_MemFindb(InChar, 0);
	char* TempChar = new char[InCharLength + InString.size() + 1];
	Simple_MemMovs(TempChar, InChar, InCharLength);
	Simple_MemMovs(TempChar + InCharLength, InString.begin(), InString.size());
	TempChar[InCharLength + InString.size()] = 0;
	delete[]InChar;
	InChar = TempChar;
	return InChar;
}