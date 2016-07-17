#pragma once

class SIMPLE_TEXTREADER {
protected:
	char *Data = nullptr;
	uint64 Length = 0, MemLength = 0;

public:
	uint64 Pointer = 0;
	//IgnoreList 在开头忽略,其他位置出现将作为分隔符
	SIMPLE_COMPRESSED_BOOL_ARRAY<128> IgnoreList;
	SIMPLE_COMPRESSED_BOOL_ARRAY<128> SeparatorList;
	bool AllowAbove128 = true, UsingIgnore = false, UsingSeparator = false;

	FORCEINLINE SIMPLE_TEXTREADER() { }
	SIMPLE_TEXTREADER(const char *InChar);
	SIMPLE_TEXTREADER(const SIMPLE_STRING &InString);
	FORCEINLINE void clear() { if(Data)delete[]Data; Length = Pointer = MemLength = 0; Data = nullptr; }
	FORCEINLINE char* ReadingPoint() { return Data + Pointer; }
	FORCEINLINE char ReadingChar() { return Data[Pointer]; }
	FORCEINLINE bool EndOfText() { return Pointer >= Length; }
	FORCEINLINE ~SIMPLE_TEXTREADER() { clear(); }
	
	FORCEINLINE void SetIgnore				(char IgnoreChar, bool IsIgnore)		{ if((uint8) IgnoreChar < 128)IgnoreList[(uint8) IgnoreChar] = IsIgnore; }
	FORCEINLINE void AddIgnore				(char IgnoreChar)						{ if((uint8) IgnoreChar < 128)IgnoreList[(uint8) IgnoreChar] = true; }
	FORCEINLINE void DelIgnore				(char IgnoreChar)						{ if((uint8) IgnoreChar < 128)IgnoreList[(uint8) IgnoreChar] = false; }
	FORCEINLINE void DeleteIgnore			(char IgnoreChar)						{ if((uint8) IgnoreChar < 128)IgnoreList[(uint8) IgnoreChar] = false; }
	FORCEINLINE void SetIgnoreChar			(char IgnoreChar, bool IsIgnore)		{ if((uint8) IgnoreChar < 128)IgnoreList[(uint8) IgnoreChar] = IsIgnore; }
	FORCEINLINE void AddIgnoreChar			(char IgnoreChar)						{ if((uint8) IgnoreChar < 128)IgnoreList[(uint8) IgnoreChar] = true; }
	FORCEINLINE void DelIgnoreChar			(char IgnoreChar)						{ if((uint8) IgnoreChar < 128)IgnoreList[(uint8) IgnoreChar] = false; }
	FORCEINLINE void DeleteIgnoreChar		(char IgnoreChar)						{ if((uint8) IgnoreChar < 128)IgnoreList[(uint8) IgnoreChar] = false; }
	
	FORCEINLINE void SetSeparator			(char SeparatorChar, bool IsSeparator)	{ if((uint8) SeparatorChar < 128)SeparatorList[(uint8) SeparatorChar] = IsSeparator; }
	FORCEINLINE void AddSeparator			(char SeparatorChar)					{ if((uint8) SeparatorChar < 128)SeparatorList[(uint8) SeparatorChar] = true; }
	FORCEINLINE void DelSeparator			(char SeparatorChar)					{ if((uint8) SeparatorChar < 128)SeparatorList[(uint8) SeparatorChar] = false; }
	FORCEINLINE void DeleteSeparator		(char SeparatorChar)					{ if((uint8) SeparatorChar < 128)SeparatorList[(uint8) SeparatorChar] = false; }
	FORCEINLINE void SetIgnoreSeparator		(char SeparatorChar, bool IsSeparator)	{ if((uint8) SeparatorChar < 128)SeparatorList[(uint8) SeparatorChar] = IsSeparator; }
	FORCEINLINE void AddIgnoreSeparator		(char SeparatorChar)					{ if((uint8) SeparatorChar < 128)SeparatorList[(uint8) SeparatorChar] = true; }
	FORCEINLINE void DelIgnoreSeparator		(char SeparatorChar)					{ if((uint8) SeparatorChar < 128)SeparatorList[(uint8) SeparatorChar] = false; }
	FORCEINLINE void DeleteIgnoreSeparator	(char SeparatorChar)					{ if((uint8) SeparatorChar < 128)SeparatorList[(uint8) SeparatorChar] = false; }
	
	FORCEINLINE void SkipIgnoreChar() { if(!UsingIgnore)return; while((uint8) Data[Pointer] < 128 && IgnoreList[(uint8) Data[Pointer]] && Pointer <= Length)Pointer++; }

	FORCEINLINE void Forward() { if(Pointer < Length)Pointer++; }
	FORCEINLINE void Back() { if(Pointer > 0)Pointer--; }
	FORCEINLINE void Forward(uint64 count) { if(Pointer + count <= Length)Pointer += count; }
	FORCEINLINE void Back(uint64 count) { if(Pointer >= count)Pointer -= count; }
	FORCEINLINE void Reset() { Pointer = 0ull; }
	
	void UseDefaultIgnore();
	void UseDefaultSeparator();

	//[Read/Get/Skip][EnglishWord/***Number] 处理优先级:忽略字符(仅在开头忽略)>分隔符>读取内容

	void ReadEnglishWord(char *buffer, uint64 BufferSize);
	void ReadEnglishWord(SIMPLE_STRING &BufferString);
	SIMPLE_STRING ReadEnglishWord();
	void GetEnglishWord(char *buffer, uint64 BufferSize);
	void GetEnglishWord(SIMPLE_STRING &BufferString);
	SIMPLE_STRING GetEnglishWord();
	uint32 SkipEnglishWord();
	
	void ReadOCTNumber(char *buffer, uint64 BufferSize);
	void ReadOCTNumber(SIMPLE_STRING &BufferString);
	SIMPLE_STRING ReadOCTNumber();
	void GetOCTNumber(char *buffer, uint64 BufferSize);
	void GetOCTNumber(SIMPLE_STRING &BufferString);
	SIMPLE_STRING GetOCTNumber();
	uint32 SkipOCTNumber();
	
	void ReadDECNumber(char *buffer, uint64 BufferSize);
	void ReadDECNumber(SIMPLE_STRING &BufferString);
	SIMPLE_STRING ReadDECNumber();
	void GetDECNumber(char *buffer, uint64 BufferSize);
	void GetDECNumber(SIMPLE_STRING &BufferString);
	SIMPLE_STRING GetDECNumber();
	uint32 SkipDECNumber();
	
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

	void ReadWord(char *buffer, uint64 BufferSize);
	void ReadWord(SIMPLE_STRING &BufferString);
	SIMPLE_STRING ReadWord();
	void GetWord(char *buffer, uint64 BufferSize);
	void GetWord(SIMPLE_STRING &BufferString);
	SIMPLE_STRING GetWord();
	uint32 SkipWord();

	//[Read/Get/Skip][Separator/Separators] 处理优先级:忽略字符(仅在开头忽略)>读取内容(分隔符)

	void ReadSeparator(char *buffer, uint64 BufferSize);
	void ReadSeparator(SIMPLE_STRING &BufferString);
	void ReadSeparator(char &BufferChar);
	char ReadSeparator();
	void GetSeparator(char *buffer, uint64 BufferSize);
	void GetSeparator(SIMPLE_STRING &BufferString);
	void GetSeparator(char &BufferChar);
	char GetSeparator();
	uint32 SkipSeparator();

	void ReadSeparators(char *buffer, uint64 BufferSize);
	void ReadSeparators(SIMPLE_STRING &BufferString);
	SIMPLE_STRING ReadSeparators();
	void GetSeparators(char *buffer, uint64 BufferSize);
	void GetSeparators(SIMPLE_STRING &BufferString);
	SIMPLE_STRING GetSeparators();
	uint32 SkipSeparators();

	//[Read/Get/Skip]Char 忽略IgnoreList和SeparatorList,直接读取字符

	void ReadChar(char *buffer, uint64 BufferSize);
	void ReadChar(SIMPLE_STRING &BufferString);
	void ReadChar(char &BufferChar);
	char ReadChar();
	void GetChar(char *buffer, uint64 BufferSize);
	void GetChar(SIMPLE_STRING &BufferString);
	void GetChar(char &BufferChar);
	char GetChar();
	uint32 SkipChar();

	//[Read/Get/Skip]Char (Limit) 忽略IgnoreList和SeparatorList,直接读取字符,不读取超过128的字符

	void ReadChar(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	void ReadChar(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	SIMPLE_STRING ReadChar(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	void GetChar(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	void GetChar(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	SIMPLE_STRING GetChar(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	uint32 SkipChar(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);

	//[Read/Get/Skip]String 忽略IgnoreList和SeparatorList,直接读取字符

	void ReadString(char *buffer, uint64 count);
	void ReadString(SIMPLE_STRING &BufferString, uint64 count);
	SIMPLE_STRING ReadString(uint64 count);
	void GetString(char *buffer, uint64 count);
	void GetString(SIMPLE_STRING &BufferString, uint64 count);
	SIMPLE_STRING GetString(uint64 count);

	//[Read/Get/Skip]String (Limit) 忽略IgnoreList和SeparatorList,直接读取字符,根据AllowAbove128确定是否读取超过128的字符 

	void ReadString(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	void ReadString(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	SIMPLE_STRING ReadString(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	void GetString(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	void GetString(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	SIMPLE_STRING GetString(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);
	uint32 SkipString(SIMPLE_COMPRESSED_BOOL_ARRAY<128> Limit);

	//所有 [Read/Get/Skip]Until 忽略IgnoreList和SeparatorList

	void ReadUntil(char *buffer, uint64 BufferSize, char end);
	void ReadUntil(SIMPLE_STRING &BufferString, char end);
	SIMPLE_STRING ReadUntil(char end);
	void GetUntil(char *buffer, uint64 BufferSize, char end);
	void GetUntil(SIMPLE_STRING &BufferString, char end);
	SIMPLE_STRING GetUntil(char end);
	uint32 SkipUntil(char end);

	void ReadUntil(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> end);
	void ReadUntil(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> end);
	SIMPLE_STRING ReadUntil(SIMPLE_COMPRESSED_BOOL_ARRAY<128> end);
	void GetUntil(char *buffer, uint64 BufferSize, SIMPLE_COMPRESSED_BOOL_ARRAY<128> end);
	void GetUntil(SIMPLE_STRING &BufferString, SIMPLE_COMPRESSED_BOOL_ARRAY<128> end);
	SIMPLE_STRING GetUntil(SIMPLE_COMPRESSED_BOOL_ARRAY<128> end);
	uint32 SkipUntil(SIMPLE_COMPRESSED_BOOL_ARRAY<128> end);

	//[Read/Get/Skip]UntilSeparator 忽略IgnoreList

	void ReadUntilSeparator(char *buffer, uint64 BufferSize);
	void ReadUntilSeparator(SIMPLE_STRING &BufferString);
	SIMPLE_STRING ReadUntilSeparator();
	void GetUntilSeparator(char *buffer, uint64 BufferSize);
	void GetUntilSeparator(SIMPLE_STRING &BufferString);
	SIMPLE_STRING GetUntilSeparator();
	uint32 SkipUntilSeparator();

	//[Read/Get/Skip]Line 忽略IgnoreList和SeparatorList

	void ReadLine(char *buffer, uint64 BufferSize);
	void ReadLine(SIMPLE_STRING &BufferString);
	SIMPLE_STRING ReadLine();
	void GetLine(char *buffer, uint64 BufferSize);
	void GetLine(SIMPLE_STRING &BufferString);
	SIMPLE_STRING GetLine();
	uint32 SkipLine();
};