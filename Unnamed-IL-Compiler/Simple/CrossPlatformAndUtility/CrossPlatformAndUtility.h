#pragma once

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#include <time.h>
#endif
#include <thread>

#ifdef _WIN64
void Simple_MemMovsb(uint64 count, const void *dst, const void *src);
void Simple_MemMovsw(uint64 count, const void *dst, const void *src);
void Simple_MemMovsd(uint64 count, const void *dst, const void *src);
void Simple_MemMovsq(uint64 count, const void *dst, const void *src);

uint64 Simple_MemFindb(const void *start, const uint8 byte);
uint64 Simple_MemFindw(const void *start, const uint16 word);
uint64 Simple_MemFindd(const void *start, const uint32 dword);
uint64 Simple_MemFindq(const void *start, const uint64 qword);

void Simple_MemMoveHighb(const void *Pointer, const uint64 count, const uint64 offset);
void Simple_MemMoveHighw(const void *Pointer, const uint64 count, const uint64 offset);
void Simple_MemMoveHighd(const void *Pointer, const uint64 count, const uint64 offset);
void Simple_MemMoveHighq(const void *Pointer, const uint64 count, const uint64 offset);

void Simple_MemMoveLowb(const void *Pointer, const uint64 count, const uint64 offset);
void Simple_MemMoveLoww(const void *Pointer, const uint64 count, const uint64 offset);
void Simple_MemMoveLowd(const void *Pointer, const uint64 count, const uint64 offset);
void Simple_MemMoveLowq(const void *Pointer, const uint64 count, const uint64 offset);
#else
FORCEINLINE void Simple_MemMovsb(uint64 count, const void *dst, const void *src) {
	for(uint32 i = 0; i < count; i++) {
		((uint8*) dst)[i] = ((uint8*) src)[i];
	}
}
FORCEINLINE void Simple_MemMovsw(uint64 count, const void *dst, const void *src) {
	for(uint32 i = 0; i < count; i++) {
		((uint16*) dst)[i] = ((uint16*) src)[i];
	}
}
FORCEINLINE void Simple_MemMovsd(uint64 count, const void *dst, const void *src) {
	for(uint32 i = 0; i < count; i++) {
		((uint32*) dst)[i] = ((uint32*) src)[i];
	}
}
FORCEINLINE void Simple_MemMovsq(uint64 count, const void *dst, const void *src) {
	for(uint32 i = 0; i < count; i++) {
		((uint64*) dst)[i] = ((uint64*) src)[i];
	}
}

FORCEINLINE uint64 Simple_MemFindb(const void *start, uint8 InByte) {
	uint64 index;
	for(index = 0; ((uint8*) start)[index] != InByte; index++);
	return index;
}
FORCEINLINE uint64 Simple_MemFindw(const void *start, uint16 InWord) {
	uint64 index;
	for(index = 0; ((uint16*) start)[index] != InWord; index++);
	return index;
}
FORCEINLINE uint64 Simple_MemFindd(const void *start, uint32 InDword) {
	uint64 index;
	for(index = 0; ((uint32*) start)[index] != InDword; index++);
	return index;
}
FORCEINLINE uint64 Simple_MemFindq(const void *start, uint64 InQword) {
	uint64 index;
	for(index = 0; ((uint64*) start)[index] != InQword; index++);
	return index;
}

FORCEINLINE void Simple_MemMoveHighb(const void *Pointer, const uint64 count, const uint64 offset) {
	uint8 *SrcPointer = ((uint8*) Pointer) + count - 1;
	uint8 *DstPointer = SrcPointer + offset;
	uint8 *EndPointer = ((uint8*) Pointer);
	for(; SrcPointer >= EndPointer; DstPointer--, SrcPointer--) {
		*DstPointer = *(uint8*) SrcPointer;
	}
}
FORCEINLINE void Simple_MemMoveHighw(const void *Pointer, const uint64 count, const uint64 offset) {
	uint16 *SrcPointer = ((uint16*) Pointer) + count - 1;
	uint16 *DstPointer = SrcPointer + offset;
	uint16 *EndPointer = ((uint16*) Pointer);
	for(; SrcPointer >= EndPointer; DstPointer--, SrcPointer--) {
		*DstPointer = *(uint16*) SrcPointer;
	}
}
FORCEINLINE void Simple_MemMoveHighd(const void *Pointer, const uint64 count, const uint64 offset) {
	uint32 *SrcPointer = ((uint32*) Pointer) + count - 1;
	uint32 *DstPointer = SrcPointer + offset;
	uint32 *EndPointer = ((uint32*) Pointer);
	for(; SrcPointer >= EndPointer; DstPointer--, SrcPointer--) {
		*DstPointer = *(uint32*) SrcPointer;
	}
}
FORCEINLINE void Simple_MemMoveHighq(const void *Pointer, const uint64 count, const uint64 offset) {
	uint64 *SrcPointer = ((uint64*) Pointer) + count - 1;
	uint64 *DstPointer = SrcPointer + offset;
	uint64 *EndPointer = ((uint64*) Pointer);
	for(; SrcPointer >= EndPointer; DstPointer--, SrcPointer--) {
		*DstPointer = *(uint64*) SrcPointer;
	}
}

FORCEINLINE void Simple_MemMoveLowb(const void *Pointer, const uint64 count, const uint64 offset) {
	uint8 *SrcPointer = ((uint8*) Pointer);
	uint8 *DstPointer = ((uint8*) Pointer) - offset;
	uint8 *EndPointer = ((uint8*) Pointer) + count;
	for(; SrcPointer < EndPointer; DstPointer++, SrcPointer++) {
		*DstPointer = *(uint8*) SrcPointer;
	}
}
FORCEINLINE void Simple_MemMoveLoww(const void *Pointer, const uint64 count, const uint64 offset) {
	uint16 *SrcPointer = ((uint16*) Pointer);
	uint16 *DstPointer = ((uint16*) Pointer) - offset;
	uint16 *EndPointer = ((uint16*) Pointer) + count;
	for(; SrcPointer < EndPointer; DstPointer++, SrcPointer++) {
		*DstPointer = *(uint16*) SrcPointer;
	}
}
FORCEINLINE void Simple_MemMoveLowd(const void *Pointer, const uint64 count, const uint64 offset) {
	uint32 *SrcPointer = ((uint32*) Pointer);
	uint32 *DstPointer = ((uint32*) Pointer) - offset;
	uint32 *EndPointer = ((uint32*) Pointer) + count;
	for(; SrcPointer < EndPointer; DstPointer++, SrcPointer++) {
		*DstPointer = *(uint32*) SrcPointer;
	}
}
FORCEINLINE void Simple_MemMoveLowq(const void *Pointer, const uint64 count, const uint64 offset) {
	uint64 *SrcPointer = ((uint64*) Pointer);
	uint64 *DstPointer = ((uint64*) Pointer) - offset;
	uint64 *EndPointer = ((uint64*) Pointer) + count;
	for(; SrcPointer < EndPointer; DstPointer++, SrcPointer++) {
		*DstPointer = *(uint64*) SrcPointer;
	}
}
#endif

template<uint32 Value>
struct SIMPLE_FUNCTIONSELECTOR { };

template<typename type, type... Value>
struct SIMPLE_SELECTOR { };

FORCEINLINE void Simple_MemMovs(const void *dst, const void *src, uint64 count, SIMPLE_FUNCTIONSELECTOR<1>) {
	Simple_MemMovsb(count, dst, src);
}

FORCEINLINE void Simple_MemMovs(const void *dst, const void *src, uint64 count, SIMPLE_FUNCTIONSELECTOR<2>) {
	Simple_MemMovsw(count, dst, src);
}

FORCEINLINE void Simple_MemMovs(const void *dst, const void *src, uint64 count, SIMPLE_FUNCTIONSELECTOR<4>) {
	Simple_MemMovsd(count, dst, src);
}

FORCEINLINE void Simple_MemMovs(const void *dst, const void *src, uint64 count, SIMPLE_FUNCTIONSELECTOR<8>) {
	Simple_MemMovsq(count, dst, src);
}

template <uint32 size>
FORCEINLINE void Simple_MemMovs(const void *dst, const void *src, uint64 count) {
	Simple_MemMovs(dst, src, count * (size / ((size % 8 == 0) ? 8 : ((size % 4 == 0) ? 4 : ((size % 2 == 0) ? 2 : 1)))), SIMPLE_FUNCTIONSELECTOR<((size % 8 == 0) ? 8 : ((size % 4 == 0) ? 4 : ((size % 2 == 0) ? 2 : 1)))>());
}

template <typename Type>
FORCEINLINE void Simple_MemMovs(const Type *dst, const Type *src, uint64 count) {
	Simple_MemMovs<sizeof(Type)>(dst, src, count);
}

#include "Time.h"
#include "Array.h"
#include "CompressedBoolArray.h"