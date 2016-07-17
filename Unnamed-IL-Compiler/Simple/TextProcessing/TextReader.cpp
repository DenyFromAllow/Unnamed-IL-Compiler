#include "../simple.h"

SIMPLE_TEXTREADER::SIMPLE_TEXTREADER(const char *InChar) {
	Length = Simple_MemFindb(InChar, 0);
	MemLength = Length + 1;
	Data = new char[(uint32) MemLength];
	Simple_MemMovsb(MemLength, Data, InChar);
}
SIMPLE_TEXTREADER::SIMPLE_TEXTREADER(const SIMPLE_STRING &InString) {
	Length = InString.size();
	MemLength = Length + 1;
	Data = new char[(uint32) MemLength];
	Simple_MemMovsb(MemLength, Data, InString.begin());
}

void SIMPLE_TEXTREADER::UseDefaultIgnore() {
	IgnoreList.clear();
	IgnoreList[' '] = true;
	IgnoreList['\n'] = true;
	IgnoreList['	'] = true;

}

void SIMPLE_TEXTREADER::UseDefaultSeparator() {
	SeparatorList.clear();
	SeparatorList[','] = true;
	SeparatorList['.'] = true;
	SeparatorList['/'] = true;
	SeparatorList['<'] = true;
	SeparatorList['>'] = true;
	SeparatorList['?'] = true;
	SeparatorList[';'] = true;
	SeparatorList[':'] = true;
	SeparatorList['\''] = true;
	SeparatorList['"'] = true;
	SeparatorList['['] = true;
	SeparatorList[']'] = true;
	SeparatorList['{'] = true;
	SeparatorList['}'] = true;
	SeparatorList['|'] = true;
	SeparatorList['\\'] = true;
	SeparatorList['`'] = true;
	SeparatorList['~'] = true;
	SeparatorList['!'] = true;
	SeparatorList['@'] = true;
	SeparatorList['#'] = true;
	SeparatorList['%'] = true;
	SeparatorList['^'] = true;
	SeparatorList['&'] = true;
	SeparatorList['*'] = true;
	SeparatorList['('] = true;
	SeparatorList[')'] = true;
	SeparatorList['-'] = true;
	SeparatorList['='] = true;
	SeparatorList['+'] = true;
}

//[Read/Get/Skip][EnglishWord/***Number] 处理优先级:忽略字符(仅在开头忽略)>分隔符>读取内容

void SIMPLE_TEXTREADER::ReadEnglishWord(char *buffer, uint64 BufferSize) {
	SkipIgnoreChar();
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 'a' && ReadingChar() <= 'z') || (ReadingChar() >= 'A' && ReadingChar() <= 'Z')) &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadEnglishWord(SIMPLE_STRING &BufferString) {
	SkipIgnoreChar();
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 'a' && ReadingChar() <= 'z') || (ReadingChar() >= 'A' && ReadingChar() <= 'Z')) &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadEnglishWord() {
	SkipIgnoreChar();
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 'a' && ReadingChar() <= 'z') || (ReadingChar() >= 'A' && ReadingChar() <= 'Z')) &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetEnglishWord(char *buffer, uint64 BufferSize) {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 'a' && ReadingChar() <= 'z') || (ReadingChar() >= 'A' && ReadingChar() <= 'Z')) &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetEnglishWord(SIMPLE_STRING &BufferString) {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 'a' && ReadingChar() <= 'z') || (ReadingChar() >= 'A' && ReadingChar() <= 'Z')) &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetEnglishWord() {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 'a' && ReadingChar() <= 'z') || (ReadingChar() >= 'A' && ReadingChar() <= 'Z')) &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipEnglishWord() {
	SkipIgnoreChar();
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 'a' && ReadingChar() <= 'z') || (ReadingChar() >= 'A' && ReadingChar() <= 'Z')) &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, SkipLength++);
	return SkipLength;
}

void SIMPLE_TEXTREADER::ReadOCTNumber(char *buffer, uint64 BufferSize) {
	SkipIgnoreChar();
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '7') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadOCTNumber(SIMPLE_STRING &BufferString) {
	SkipIgnoreChar();
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '7') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadOCTNumber() {
	SkipIgnoreChar();
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '7') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetOCTNumber(char *buffer, uint64 BufferSize) {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '7') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetOCTNumber(SIMPLE_STRING &BufferString) {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '7') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetOCTNumber() {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '7') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipOCTNumber() {
	SkipIgnoreChar();
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '7') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, SkipLength++);
		return SkipLength;
}

void SIMPLE_TEXTREADER::ReadDECNumber(char *buffer, uint64 BufferSize) {
	SkipIgnoreChar();
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '9') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadDECNumber(SIMPLE_STRING &BufferString) {
	SkipIgnoreChar();
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '9') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadDECNumber() {
	SkipIgnoreChar();
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '9') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetDECNumber(char *buffer, uint64 BufferSize) {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '9') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetDECNumber(SIMPLE_STRING &BufferString) {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '9') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetDECNumber() {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '9') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipDECNumber() {
	SkipIgnoreChar();
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		(ReadingChar() >= '0' && ReadingChar() <= '9') &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]);
		Pointer++, SkipLength++);
		return SkipLength;
}

void ReadHEXNumber(char *buffer, uint64 BufferSize);
void ReadHEXNumber(SIMPLE_STRING &BufferString);
SIMPLE_STRING ReadHEXNumber();
void GetHEXNumber(char *buffer, uint64 BufferSize);
void GetHEXNumber(SIMPLE_STRING &BufferString);
SIMPLE_STRING GetHEXNumber();
uint32 SkipHEXNumber();

void ReadNumber(char *buffer, uint64 BufferSize);
void ReadNumber(SIMPLE_STRING &BufferString);
SIMPLE_STRING ReadNumber();
void GetNumber(char *buffer, uint64 BufferSize);
void GetNumber(SIMPLE_STRING &BufferString);
SIMPLE_STRING GetNumber();
uint32 SkipNumber();

//遇到分隔符停止,不忽略IgnoreList

void SIMPLE_TEXTREADER::ReadWord(char *buffer, uint64 BufferSize)
{
	SkipIgnoreChar();
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length && 
		((ReadingChar() >= 128&&AllowAbove128) ||
		(ReadingChar() < 128 &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]))) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadWord(SIMPLE_STRING &BufferString) {
	SkipIgnoreChar();
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128&&AllowAbove128) ||
		(ReadingChar() < 128 &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()])));
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadWord() {
	SkipIgnoreChar();
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128&&AllowAbove128) ||
		(ReadingChar() < 128 &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()])));
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetWord(char *buffer, uint64 BufferSize) {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128&&AllowAbove128) ||
		(ReadingChar() < 128 &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()]))) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetWord(SIMPLE_STRING &BufferString) {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128&&AllowAbove128) ||
		(ReadingChar() < 128 &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()])));
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetWord() {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128&&AllowAbove128) ||
		(ReadingChar() < 128 &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()])));
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipWord() {
	SkipIgnoreChar();
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128&&AllowAbove128) ||
		(ReadingChar() < 128 &&
		!(UsingSeparator&&SeparatorList[ReadingChar()]) &&
		!(UsingIgnore&&IgnoreList[ReadingChar()])));
		Pointer++, SkipLength++);
		return SkipLength;
}

//[Read/Get/Skip][Separator/Separators] 处理优先级:忽略字符(仅在开头忽略)>读取内容(分隔符)

void SIMPLE_TEXTREADER::ReadSeparator(char *buffer, uint64 BufferSize) {
	if(BufferSize < 2)return;
	SkipIgnoreChar();
	if(Pointer < Length && UsingSeparator && ReadingChar() < 128 && SeparatorList[ReadingChar()]) {
		buffer[0] = ReadingChar();
		buffer[1] = 0;
		Pointer++;
	} else {
		buffer[0] = 0;
	}
}
void SIMPLE_TEXTREADER::ReadSeparator(SIMPLE_STRING &BufferString) {
	SkipIgnoreChar();
	BufferString.clear();
	if(Pointer < Length && UsingSeparator && ReadingChar() < 128 && SeparatorList[ReadingChar()]) {
		BufferString.PushBack(ReadingChar());
		Pointer++;
	}
}
void SIMPLE_TEXTREADER::ReadSeparator(char &BufferChar) {
	SkipIgnoreChar();
	if(Pointer < Length && UsingSeparator && ReadingChar() < 128 && SeparatorList[ReadingChar()]) {
		BufferChar = ReadingChar();
		Pointer++;
	} else {
		BufferChar = 0;
	}
}
char SIMPLE_TEXTREADER::ReadSeparator() {
	SkipIgnoreChar();
	if(Pointer < Length && UsingSeparator && ReadingChar() < 128 && SeparatorList[ReadingChar()]) {
		return Data[Pointer++];
	} else {
		return 0;
	}
}
void SIMPLE_TEXTREADER::GetSeparator(char *buffer, uint64 BufferSize) {
	if(BufferSize < 2)return;
	SkipIgnoreChar();
	if(Pointer < Length && UsingSeparator && ReadingChar() < 128 && SeparatorList[ReadingChar()]) {
		buffer[0] = ReadingChar();
		buffer[1] = 0;
	} else {
		buffer[0] = 0;
	}
}
void SIMPLE_TEXTREADER::GetSeparator(SIMPLE_STRING &BufferString) {
	SkipIgnoreChar();
	BufferString.clear();
	if(Pointer < Length && UsingSeparator && ReadingChar() < 128 && SeparatorList[ReadingChar()]) {
		BufferString.PushBack(ReadingChar());
	}
}
void SIMPLE_TEXTREADER::GetSeparator(char &BufferChar) {
	SkipIgnoreChar();
	if(Pointer < Length && UsingSeparator && ReadingChar() < 128 && SeparatorList[ReadingChar()]) {
		BufferChar = ReadingChar();
	} else {
		BufferChar = 0;
	}
}
char SIMPLE_TEXTREADER::GetSeparator() {
	SkipIgnoreChar();
	if(Pointer < Length && UsingSeparator && ReadingChar() < 128 && SeparatorList[ReadingChar()]) {
		return ReadingChar();
	} else {
		return 0;
	}
}
uint32 SIMPLE_TEXTREADER::SkipSeparator() {
	SkipIgnoreChar();
	uint64 oldPointer = Pointer;
	if(Pointer < Length && UsingSeparator && ReadingChar() < 128 && SeparatorList[ReadingChar()]) {
		Pointer++;
	}
	return Pointer - oldPointer;
}

void SIMPLE_TEXTREADER::ReadSeparators(char *buffer, uint64 BufferSize) {
	SkipIgnoreChar();
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar() < 128 &&
		UsingSeparator && SeparatorList[ReadingChar()] &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadSeparators(SIMPLE_STRING &BufferString) {
	SkipIgnoreChar();
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar() < 128 &&
		UsingSeparator && SeparatorList[ReadingChar()];
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadSeparators() {
	SkipIgnoreChar();
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar()<128 &&
		UsingSeparator && SeparatorList[ReadingChar()];
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetSeparators(char *buffer, uint64 BufferSize) {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar()<128 &&
		UsingSeparator && SeparatorList[ReadingChar()] &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetSeparators(SIMPLE_STRING &BufferString) {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar()<128 &&
		UsingSeparator && SeparatorList[ReadingChar()];
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetSeparators() {
	uint64 BackupPointer = Pointer;
	SkipIgnoreChar();
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar()<128 &&
		UsingSeparator && SeparatorList[ReadingChar()];
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipSeparators() {
	SkipIgnoreChar();
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		ReadingChar()<128 &&
		UsingSeparator && SeparatorList[ReadingChar()];
		Pointer++, SkipLength++);
		return SkipLength;
}

//[Read/Get/Skip]Char 忽略IgnoreList和SeparatorList,直接读取字符

void SIMPLE_TEXTREADER::ReadChar(char *buffer, uint64 BufferSize) {
	if(BufferSize < 2)return;
	if(Pointer < Length) {
		buffer[0] = Data[Pointer++];
		buffer[1] = 0;
	} else {
		buffer[0] = 0;
	}
}
void SIMPLE_TEXTREADER::ReadChar(SIMPLE_STRING &BufferString) {
	if(Pointer < Length) {
		BufferString = Data[Pointer++];
	} else {
		BufferString.clear();
	}
}
void SIMPLE_TEXTREADER::ReadChar(char &BufferChar) {
	if(Pointer < Length) {
		BufferChar = Data[Pointer++];
	} else {
		BufferChar = 0;
	}
}
char SIMPLE_TEXTREADER::ReadChar() {
	if(Pointer < Length) {
		return Data[Pointer++];
	} else {
		return 0;
	}
}
void SIMPLE_TEXTREADER::GetChar(char *buffer, uint64 BufferSize) {
	if(BufferSize < 2)return;
	if(Pointer < Length) {
		buffer[0] = Data[Pointer];
		buffer[1] = 0;
	} else {
		buffer[0] = 0;
	}
}
void SIMPLE_TEXTREADER::GetChar(SIMPLE_STRING &BufferString) {
	if(Pointer < Length) {
		BufferString = Data[Pointer];
	} else {
		BufferString.clear();
	}
}
void SIMPLE_TEXTREADER::GetChar(char &BufferChar) {
	if(Pointer < Length) {
		BufferChar = Data[Pointer];
	} else {
		BufferChar = 0;
	}
}
char SIMPLE_TEXTREADER::GetChar() {
	if(Pointer < Length) {
		return Data[Pointer++];
	} else {
		return 0;
	}
}
uint32 SIMPLE_TEXTREADER::SkipChar() {
	uint64 oldPointer = Pointer;
	if(Pointer < Length) Pointer++;
	return Pointer - oldPointer;
}
//[Read/Get/Skip]Char (Limit) 忽略IgnoreList和SeparatorList,直接读取字符,不读取超过128的字符

void SIMPLE_TEXTREADER::ReadChar(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar() < 128 &&
		Limit[ReadingChar()] &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadChar(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar() < 128 &&
		Limit[ReadingChar()];
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadChar(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar() < 128 &&
		Limit[ReadingChar()];
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetChar(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	uint64 BackupPointer = Pointer;
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar() < 128 &&
		Limit[ReadingChar()] &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetChar(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	uint64 BackupPointer = Pointer;
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar() < 128 &&
		Limit[ReadingChar()];
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetChar(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	uint64 BackupPointer = Pointer;
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		ReadingChar() < 128 &&
		Limit[ReadingChar()];
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipChar(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		ReadingChar() < 128 &&
		Limit[ReadingChar()];
		Pointer++, SkipLength++);
		return SkipLength;
}

//[Read/Get/Skip]String 忽略IgnoreList和SeparatorList,直接读取字符

void SIMPLE_TEXTREADER::ReadString(char *buffer, uint64 count) {
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		BufferIndex < count;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadString(SIMPLE_STRING &BufferString, uint64 count) {
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		BufferIndex < count;
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadString(uint64 count) {
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		BufferIndex < count;
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetString(char *buffer, uint64 count) {
	uint64 BackupPointer = Pointer;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		BufferIndex < count;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetString(SIMPLE_STRING &BufferString, uint64 count) {
	uint64 BackupPointer = Pointer;
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		BufferIndex < count;
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetString(uint64 count) {
	uint64 BackupPointer = Pointer;
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		BufferIndex < count;
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}

//[Read/Get/Skip]String (Limit) 忽略IgnoreList和SeparatorList,直接读取字符,根据AllowAbove128确定是否读取超过128的字符 

void SIMPLE_TEXTREADER::ReadString(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128 && AllowAbove128) ||
		(ReadingChar() < 128 &&
		Limit[ReadingChar()])) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadString(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128 && AllowAbove128) ||
		(ReadingChar() < 128 &&
		Limit[ReadingChar()]));
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadString(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128 && AllowAbove128) ||
		(ReadingChar() < 128 &&
		Limit[ReadingChar()]));
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetString(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	uint64 BackupPointer = Pointer;
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128 && AllowAbove128) ||
		(ReadingChar() < 128 &&
		Limit[ReadingChar()])) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetString(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	uint64 BackupPointer = Pointer;
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128 && AllowAbove128) ||
		(ReadingChar() < 128 &&
		Limit[ReadingChar()]));
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetString(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	uint64 BackupPointer = Pointer;
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128 && AllowAbove128) ||
		(ReadingChar() < 128 &&
		Limit[ReadingChar()]));
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipString(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit) {
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		((ReadingChar() >= 128 && AllowAbove128) ||
		(ReadingChar() < 128 &&
		Limit[ReadingChar()]));
		Pointer++, SkipLength++);
	return SkipLength;
}
//所有 [Read/Get/Skip]Until 忽略IgnoreList和SeparatorList

void SIMPLE_TEXTREADER::ReadUntil(char *buffer, uint64 BufferSize, char end) {
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		end!=ReadingChar() &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadUntil(SIMPLE_STRING &BufferString, char end) {
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		end != ReadingChar();
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadUntil(char end) {
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		end != ReadingChar();
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetUntil(char *buffer, uint64 BufferSize, char end) {
	uint64 BackupPointer = Pointer;
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		end != ReadingChar() &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetUntil(SIMPLE_STRING &BufferString, char end) {
	uint64 BackupPointer = Pointer;
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		end != ReadingChar();
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetUntil(char end) {
	uint64 BackupPointer = Pointer;
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		end != ReadingChar();
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipUntil(char end) {
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		end != ReadingChar();
		Pointer++, SkipLength++);
		return SkipLength;
}

void SIMPLE_TEXTREADER::ReadUntil(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> end) {
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar() < 128 &&
		end[ReadingChar()]) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadUntil(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> end) {
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar() < 128 &&
		end[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadUntil(SIMPLE_COMPRESSED_BOOL_ARRAY<128> end) {
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar() < 128 &&
		end[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetUntil(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> end) {
	uint64 BackupPointer = Pointer;
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar() < 128 &&
		end[ReadingChar()]) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetUntil(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> end) {
	uint64 BackupPointer = Pointer;
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar() < 128 &&
		end[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetUntil(SIMPLE_COMPRESSED_BOOL_ARRAY<128> end) {
	uint64 BackupPointer = Pointer;
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar() < 128 &&
		end[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipUntil(SIMPLE_COMPRESSED_BOOL_ARRAY<128> end) {
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		!(ReadingChar() < 128 &&
		end[ReadingChar()]);
		Pointer++, SkipLength++);
		return SkipLength;
}

//[Read/Get/Skip]UntilSeparator 忽略IgnoreList

void SIMPLE_TEXTREADER::ReadUntilSeparator(char *buffer, uint64 BufferSize) {
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar() < 128 &&
		UsingSeparator && SeparatorList[ReadingChar()]) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadUntilSeparator(SIMPLE_STRING &BufferString) {
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar() < 128 &&
		UsingSeparator && SeparatorList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadUntilSeparator() {
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar()<128 &&
		UsingSeparator && SeparatorList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetUntilSeparator(char *buffer, uint64 BufferSize) {
	uint64 BackupPointer = Pointer;
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar()<128 &&
		UsingSeparator && SeparatorList[ReadingChar()]) &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetUntilSeparator(SIMPLE_STRING &BufferString) {
	uint64 BackupPointer = Pointer;
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar()<128 &&
		UsingSeparator && SeparatorList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetUntilSeparator() {
	uint64 BackupPointer = Pointer;
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		!(ReadingChar()<128 &&
		UsingSeparator && SeparatorList[ReadingChar()]);
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipUntilSeparator() {
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		!(ReadingChar()<128 &&
		UsingSeparator && SeparatorList[ReadingChar()]);
		Pointer++, SkipLength++);
		return SkipLength;
}

//[Read/Get/Skip]Line 忽略IgnoreList和SeparatorList

void SIMPLE_TEXTREADER::ReadLine(char *buffer, uint64 BufferSize) {
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		if('\n' == ReadingChar()) { Pointer++; break; }

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
}
void SIMPLE_TEXTREADER::ReadLine(SIMPLE_STRING &BufferString) {
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length;
		Pointer++, BufferIndex++) {

		if('\n' == ReadingChar()) { Pointer++; break; }

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
}
SIMPLE_STRING SIMPLE_TEXTREADER::ReadLine() {
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length;
		Pointer++, BufferIndex++) {

		if('\n' == ReadingChar()) { Pointer++; break; }

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	return BufferString;
}
void SIMPLE_TEXTREADER::GetLine(char *buffer, uint64 BufferSize) {
	uint64 BackupPointer = Pointer;
	BufferSize--;
	uint64 BufferIndex = 0;
	for(; Pointer < Length &&
		'\n' != ReadingChar() &&
		BufferIndex < BufferSize;
		Pointer++, BufferIndex++) {

		buffer[BufferIndex] = ReadingChar();
	}
	buffer[BufferIndex] = 0;
	Pointer = BackupPointer;
}
void SIMPLE_TEXTREADER::GetLine(SIMPLE_STRING &BufferString) {
	uint64 BackupPointer = Pointer;
	BufferString.clear();
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		'\n' != ReadingChar();
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
}
SIMPLE_STRING SIMPLE_TEXTREADER::GetLine() {
	uint64 BackupPointer = Pointer;
	SIMPLE_STRING BufferString;
	char buffer[64];
	uint32 BufferIndex = 0;
	for(; Pointer < Length &&
		'\n' != ReadingChar();
		Pointer++, BufferIndex++) {

		if(BufferIndex >= 64) {
			BufferString.PushBack(buffer, 64);
			BufferIndex = 0;
		}
		buffer[BufferIndex] = ReadingChar();

	}
	if(BufferIndex != 0)BufferString.PushBack(buffer, BufferIndex);
	Pointer = BackupPointer;
	return BufferString;
}
uint32 SIMPLE_TEXTREADER::SkipLine() {
	uint32 SkipLength = 0;
	for(; Pointer < Length &&
		'\n' != ReadingChar();
		Pointer++, SkipLength++);
		return SkipLength;
}