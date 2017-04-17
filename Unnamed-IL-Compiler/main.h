#pragma once
#include"Simple\simple.h"
using namespace Simple;
using uint128 = uint64[2];
using uint256 = uint64[4];
using int128 = int64[2];
using int256 = int64[4];

template<typename T>
using ILCArray = AArray<T>;
#include"enum.h"
#include"structs.h"
#include <conio.h>

class ILCException {
public:

	enum ExceptionType :uint8 {
		unknown,
		EndOfText,
		EndOfCommand,
		//UnknownSeparator,
		TypeError,
		UnsupportedType,
		UnexpectedSeparator,
		IncorrectSeparator,
		FirstCharactorIsNumber,
		ElementCountIsZero,
		UnableToGetElementCount,
		DataOverflow,
		TryToInitPtr
	};

	ExceptionType type;
	uint32 line;
	String Info;

	FORCEINLINE ILCException() :type(unknown), line(NULL), Info() { }
	FORCEINLINE ILCException(ExceptionType InType) : type(InType), line(NULL), Info() { }
	FORCEINLINE ILCException(ExceptionType InType, uint32 InLine) : type(InType), line(InLine), Info() { }
	FORCEINLINE ILCException(ExceptionType InType, const String &InInfo) : type(InType), line(NULL), Info(InInfo) { }
	FORCEINLINE ILCException(ExceptionType InType, String &&InInfo) : type(InType), line(NULL), Info(InInfo) { }
	FORCEINLINE ILCException(ExceptionType InType, uint32 InLine, const String &InInfo) : type(InType), line(InLine), Info(InInfo) { }
	FORCEINLINE ILCException(ExceptionType InType, uint32 InLine, String &&InInfo) : type(InType), line(InLine), Info(InInfo) { }

	FORCEINLINE bool operator==(ExceptionType InType) { return type == InType; }
};

FORCEINLINE uint16 sizeOfType(uint32 type) {
	static const uint16 sizeArray[] = { 0,8,16,32,64,128,256,32,64,128 };
	return sizeArray[(uint8) type];
}

class typeAddressList {
	ILCArray<MemAllocation> MemoryData;
	
};

extern SIMPLE_TRIETREE MainDict;
extern SIMPLE_TRIETREE TypeDict;
extern SIMPLE_TRIETREE FunctionDict;
extern SIMPLE_TEXTREADER *SourceReader;
extern Block *currentBlock;
extern String SourceString;

void InitInstructions();
void InitTypes();
void InitReader();
bool check();
uint32 ReadType(String SourceString);
void* allocByType(VarType type, uint32 count);
void assignByType(void* pointer, uint64 value, VarType type, uint32 index);
void ReadMemoryText(uint32 Instruction, String SourceString);
void ReadDirective(uint32 directive);
void CreateFunction();