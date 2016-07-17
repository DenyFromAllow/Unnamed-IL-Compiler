#pragma once

FORCEINLINE uint64 SimpleMath_RandUint64() {
	#if RAND_MAX >= 0xFFFFFFFFFFFFFFFF
	return rand();
	#elif RAND_MAX >= 0xFFFFFFFF
	return (rand() << 32) | rand();
	#elif RAND_MAX >= 0xFFFF
	return (rand() << 48) | (rand() << 32) | (rand() << 16) | rand();
	#elif RAND_MAX >= 0xFF
	return ((int64) rand() << 56) | ((int64) rand() << 48) | ((int64) rand() << 40) | ((int64) rand() << 32) | ((int64) rand() << 24) | ((int64) rand() << 16) | ((int64) rand() << 8) | (int64) rand();
	#elif RAND_MAX >= 0xF
	return (rand() << 60) | (rand() << 56) | (rand() << 52) | (rand() << 48) | (rand() << 44) | (rand() << 40) | (rand() << 36) | (rand() << 32) |
		(rand() << 28) | (rand() << 24) | (rand() << 20) | (rand() << 16) | (rand() << 12) | (rand() << 8) | (rand() << 4) | rand();
	#endif
}
FORCEINLINE int64 SimpleMath_RandInt64() {
	#if RAND_MAX >= 0xFFFFFFFFFFFFFFFF
	return rand();
	#elif RAND_MAX >= 0xFFFFFFFF
	return (rand() << 32) | rand();
	#elif RAND_MAX >= 0xFFFF
	return (rand() << 48) | (rand() << 32) | (rand() << 16) | rand();
	#elif RAND_MAX >= 0xFF
	return ((int64) rand() << 56) | ((int64) rand() << 48) | ((int64) rand() << 40) | ((int64) rand() << 32) | ((int64) rand() << 24) | ((int64) rand() << 16) | ((int64) rand() << 8) | (int64) rand();
	#elif RAND_MAX >= 0xF
	return (rand() << 60) | (rand() << 56) | (rand() << 52) | (rand() << 48) | (rand() << 44) | (rand() << 40) | (rand() << 36) | (rand() << 32) |
		(rand() << 28) | (rand() << 24) | (rand() << 20) | (rand() << 16) | (rand() << 12) | (rand() << 8) | (rand() << 4) | rand();
	#endif
}

FORCEINLINE uint32 SimpleMath_RandUint32() {
	#if RAND_MAX >= 0xFFFFFFFF
	return rand();
	#elif RAND_MAX >= 0xFFFF
	return (rand() << 16) | rand();
	#elif RAND_MAX >= 0xFF
	return (rand() << 24) | (rand() << 16) | (rand() << 8) | rand();
	#elif RAND_MAX >= 0xF
	return (rand() << 28) | (rand() << 24) | (rand() << 20) | (rand() << 16) | (rand() << 12) | (rand() << 8) | (rand() << 4) | rand();
	#endif
}
FORCEINLINE int32 SimpleMath_RandUint32(int32 Max) {
	return (int32) floor((double) SimpleMath_RandUint32() * (Max + 1) / 4294967296.0);
}
FORCEINLINE int32 SimpleMath_RandInt32() {
	#if RAND_MAX >= 0xFFFFFFFF
	return rand();
	#elif RAND_MAX >= 0xFFFF
	return (rand() << 16) | rand();
	#elif RAND_MAX >= 0xFF
	return (rand() << 24) | (rand() << 16) | (rand() << 8) | rand();
	#elif RAND_MAX >= 0xF
	return (rand() << 28) | (rand() << 24) | (rand() << 20) | (rand() << 16) | (rand() << 12) | (rand() << 8) | (rand() << 4) | rand();
	#endif
}
FORCEINLINE int32 SimpleMath_RandInt32(int32 Max) {
	return (int32) floor((double) SimpleMath_RandUint32() * (Max + 1) / 4294967296.0);
}
FORCEINLINE int32 SimpleMath_RandInt32(int32 Min, int32 Max) {
	return (int32) floor((double) SimpleMath_RandUint32() * (Max - Min + 1) / 4294967296.0) + Min;
}

FORCEINLINE uint16 SimpleMath_RandUint16() {
	#if RAND_MAX >= 0xFFFF
	return rand();
	#elif RAND_MAX >= 0xFF
	return (rand() << 8) | rand();
	#elif RAND_MAX >= 0xF
	return (rand() << 12) | (rand() << 8) | (rand() << 4) | rand();
	#endif
}
FORCEINLINE int16 SimpleMath_RandInt16() {
	#if RAND_MAX >= 0xFFFF
	return rand();
	#elif RAND_MAX >= 0xFF
	return ((rand() << 8) | rand());
	#elif RAND_MAX >= 0xF
	return (rand() << 12) | (rand() << 8) | (rand() << 4) | rand();
	#endif
}

FORCEINLINE uint16 SimpleMath_RandUint8() {
	#if RAND_MAX >= 0xFF
	return rand();
	#elif RAND_MAX >= 0xF
	return (rand() << 4) | rand();
	#endif
}
FORCEINLINE int16 SimpleMath_RandInt8() {
	#if RAND_MAX >= 0xFF
	return rand();
	#elif RAND_MAX >= 0xF
	return (rand() << 4) | rand();
	#endif
}

FORCEINLINE float SimpleMath_RandUFloat() {
	return (float) SimpleMath_RandUint32() / 0xFFFFFFFF;
}
FORCEINLINE float SimpleMath_RandFloat() {
	return (float) SimpleMath_RandInt32() / 0x7FFFFFFF;
}
FORCEINLINE float SimpleMath_RandUFloat(float Max) {
	return (float) SimpleMath_RandUint32() * Max / 0xFFFFFFFF;
}
FORCEINLINE float SimpleMath_RandFloat(float Max) {
	return (float) SimpleMath_RandUint32() * Max / 0xFFFFFFFF;
}
FORCEINLINE float SimpleMath_RandFloat(float Min, float Max) {
	return (float) SimpleMath_RandUint32() * (Max - Min) / 0xFFFFFFFF + Min;
}

FORCEINLINE double SimpleMath_RandUDouble() {
	return (double) SimpleMath_RandUint64() / 0xFFFFFFFFFFFFFFFF;
}
FORCEINLINE double SimpleMath_RandDouble() {
	return (double) SimpleMath_RandInt64() / 0x7FFFFFFFFFFFFFFF;
}
FORCEINLINE double SimpleMath_RandUDouble(double Max) {
	return (double) SimpleMath_RandUint64() * Max / 0xFFFFFFFFFFFFFFFF;
}
FORCEINLINE double SimpleMath_RandDouble(double Max) {
	return (double) SimpleMath_RandUint64() * Max / 0xFFFFFFFFFFFFFFFF;
}
FORCEINLINE double SimpleMath_RandDouble(double Min, double Max) {
	return (double) SimpleMath_RandUint64() * (Max - Min) / 0xFFFFFFFFFFFFFFFF + Min;
}

FORCEINLINE bool SimpleMath_IsPowerOfTwo(uint32 Value) {
	return ((Value &(Value - 1)) == 0);
}

FORCEINLINE float SimpleMath_Sqrt(float Value) { return sqrtf(Value); }
FORCEINLINE double SimpleMath_Sqrt(double Value) { return sqrt(Value); }
/*
FORCEINLINE int32 UIRand() { return Simple_RandUint32(); }
FORCEINLINE int32 IRand() { return Simple_RandInt32(); }
FORCEINLINE int32 UIRand(int32 Max) { return (int32) floor((double) Simple_RandUint32() * (Max + 1) / 4294967296.0); }
FORCEINLINE int32 IRand(int32 Max) { return (int32) floor((double) Simple_RandUint32() * (Max + 1) / 4294967296.0); }
FORCEINLINE int32 IRand(int32 Min, int32 Max) { return (int32) floor((double) Simple_RandUint32() * (Max - Min + 1) / 4294967296.0) + Min; }

FORCEINLINE float UFRand() { return (float) Simple_RandUint32() / 0xFFFFFFFF; }
FORCEINLINE float FRand() { return (float) Simple_RandInt32() / 0x7FFFFFFF; }
FORCEINLINE float UFRand(float Max) { return (float) Simple_RandUint32() * Max / 0xFFFFFFFF; }
FORCEINLINE float FRand(float Max) { return (float) Simple_RandUint32() * Max / 0xFFFFFFFF; }
FORCEINLINE float FRand(float Min, float Max) { return (float) Simple_RandUint32() * (Max - Min) / 0xFFFFFFFF + Min; }

FORCEINLINE double UDRand() { return (double) Simple_RandUint64() / 0xFFFFFFFFFFFFFFFF; }
FORCEINLINE double DRand() { return (double) Simple_RandInt64() / 0x7FFFFFFFFFFFFFFF; }
FORCEINLINE double UDRand(double Max) { return (double) Simple_RandUint64() * Max / 0xFFFFFFFFFFFFFFFF; }
FORCEINLINE double FDand(double Max) { return (double) Simple_RandUint64() * Max / 0xFFFFFFFFFFFFFFFF; }
FORCEINLINE double FDand(double Min, double Max) { return (double) Simple_RandUint64() * (Max - Min) / 0xFFFFFFFFFFFFFFFF + Min; }


FORCEINLINE float sqrtfd(float Value) { return sqrtf(Value); }
FORCEINLINE double sqrtfd(double Value) { return sqrt(Value); }*/
