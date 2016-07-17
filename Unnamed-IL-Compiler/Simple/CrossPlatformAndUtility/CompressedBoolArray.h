#pragma once

class CompressBoolReference {
	#ifdef Simple_X64
	uint64 index, *Data;
	FORCEINLINE CompressBoolReference(uint64 InIndex, uint64 *InData) :index(InIndex), Data(InData) { }
	CompressBoolReference() = delete;
	CompressBoolReference(CompressBoolReference&&) = delete;
	CompressBoolReference(const CompressBoolReference&) = delete;
public:
	FORCEINLINE operator bool() { return bool((Data[index / 64] >> (index % 64)) & 1); }
	FORCEINLINE bool operator=(bool InBool) {
		uint64 ArrayIndex = index / 64;
		if(InBool)Data[ArrayIndex] |= 1ull << (index % 64);
		else Data[ArrayIndex] &= ~(1ull << (index % 64));
		return InBool;
	}
	#else
	uint64 index;
	uint32 *Data;
	FORCEINLINE CompressBoolReference(uint64 InIndex, uint32 *InData) :index(InIndex), Data(InData) { }
	CompressBoolReference() = delete;
	CompressBoolReference(CompressBoolReference&&) = delete;
	CompressBoolReference(const CompressBoolReference&) = delete;
public:
	FORCEINLINE operator bool() { return bool((Data[index / 32] >> (index % 32)) & 1); }
	FORCEINLINE bool operator=(bool InBool) {
		uint64 ArrayIndex = index / 32;
		if(InBool)Data[ArrayIndex] |= 1ul << (index % 32);
		else Data[ArrayIndex] &= ~(1ul << (index % 32));
		return InBool;
	}
	#endif
	template<uint64 Length>
	friend class SIMPLE_COMPRESSED_BOOL_ARRAY;
};

template<uint64 Length>
class SIMPLE_COMPRESSED_BOOL_ARRAY {
public:
	#ifdef Simple_X64
	uint64 Data[(Length - 1) / 64 + 1];
	FORCEINLINE SIMPLE_COMPRESSED_BOOL_ARRAY() {
		for(uint64 i = 0; i < ((Length - 1) / 64 + 1); i++)Data[i] = 0ull;
	}
	void FORCEINLINE clear() {
		for(uint64 i = 0; i < ((Length - 1) / 64 + 1); i++)Data[i] = 0ull;
	}
	#else
	uint32 Data[(Length - 1) / 32 + 1];
	FORCEINLINE SIMPLE_COMPRESSED_BOOL_ARRAY() {
		for(uint64 i = 0; i < ((Length - 1) / 32 + 1); i++)Data[i] = 0ul;
	}
	void FORCEINLINE clear() {
		for(uint64 i = 0; i < ((Length - 1) / 32 + 1); i++)Data[i] = 0ul;
	}
	#endif
	FORCEINLINE CompressBoolReference &operator[](uint64 index) { return CompressBoolReference(index, Data); }
};