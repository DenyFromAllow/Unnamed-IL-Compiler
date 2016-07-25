#pragma once
#include"Simple\simple.h"
#include <conio.h>
using namespace Simple;

enum class VarType :uint8 {
	none = 0,
	i8, b = i8,
	i16, w = i16,
	i32, d = i32,
	i64, q = i64,
	i128,
	i256,
	f,
	df,
	ld,
	ptr,
	error
};

FORCEINLINE uint16 sizeOfType(VarType type) {
	static const uint16 sizeArray[] = { 0,8,16,32,64,128,256,32,64,128 };
	return sizeArray[(uint8) type];
}

using uint128 = uint64[2];
using uint256 = uint64[4];
using int128 = int64[2];
using int256 = int64[4];

struct Variable {
	String name;
	VarType type;
	//uint32 VListPointer;
	uint32 ElementCount;
	uint32 DataCount;
	void* data;
	Variable* next;
	~Variable() { }
};

struct tempVariable {
	uint8 index;
	uint16 LifeRemaining;
	tempVariable* next;
};

extern SIMPLE_TRIETREE MainTrie;
extern SIMPLE_TEXTREADER *SourceReader;
extern AArray<Variable> Stack, Memory;
extern tempVariable* tempVariableList;

void InitInstructions();
void InitReader();
bool check();
bool checkIgnEOT();
VarType getType(String SourceString, uint32 Start);
void* allocByType(VarType type, uint32 count);
void assignByType(void* pointer, uint64 value, VarType type, uint32 index);
void Ram(uint32 Instruction, String SourceString);
