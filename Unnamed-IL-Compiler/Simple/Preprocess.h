#pragma once

#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <initializer_list>

#if !defined(_WIN64) && (defined(__WIN64__) || defined(WIN64) || defined(__MINGW64__))
#define _WIN64
#endif

#if !defined(_WIN32) && (defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__) || defined(_WIN64))
#define _WIN32
#endif

#define USE_EXPLICIT_CONVERSION false         //true or false
#define USE_CONST_AND_REFERENCE_PARAMETER 3   //3 = CONST AND REFERENCE, 2 = CONST, 1 = REFERENCE, 0 = NONE

#ifdef _M_X64
#define x86code(code)
#define x64code(code) code
#define Simple_X64
#else
#define x86code(code) code
#define x64code(code)
#define Simple_X86
#endif

#if USE_EXPLICIT_CONVERSION
#define EXPLICIT explicit
#else
#define EXPLICIT
#endif

#if USE_CONST_AND_REFERENCE_PARAMETER == 3
#define CONST const
#define REFERENCE &
#elif USE_CONST_AND_REFERENCE_PARAMETER == 2
#define CONST const
#define REFERENCE
#elif USE_CONST_AND_REFERENCE_PARAMETER == 1
#define CONST
#define REFERENCE &
#else
#define CONST
#define REFERENCE
#endif

#define SimpleMath_Abs(NUM) ((NUM > 0) ? NUM : -NUM)
#define SimpleMath_Max2(A, B) ((A > B) ? A : B)
#define SimpleMath_Min2(A, B) ((A < B) ? A : B)
#define SimpleMath_Max3(A, B, C) ((A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C))
#define SimpleMath_Min3(A, B, C) ((A < B) ? ((A < C) ? A : C) : ((B < C) ? B : C))
#define SimpleMath_Max4(A, B, C, D) ((A > B) ? ((A > C) ? ((A > D) ? A : D) : ((C > D) ? C : D)) : ((B > C) ? ((B > D) ? B : D) : ((C > D) ? C : D)))
#define SimpleMath_Min4(A, B, C, D) ((A < B) ? ((A < C) ? ((A < D) ? A : D) : ((C < D) ? C : D)) : ((B < C) ? ((B < D) ? B : D) : ((C < D) ? C : D)))
#define SimpleMath_AbsMax2(A, B) SimpleMath_Max2(SimpleMath_Abs(A), SimpleMath_Abs(B))
#define SimpleMath_AbsMin2(A, B) SimpleMath_Min2(SimpleMath_Abs(A), SimpleMath_Abs(B))
#define SimpleMath_AbsMax3(A, B, C) SimpleMath_Max3(SimpleMath_Abs(A), SimpleMath_Abs(B), SimpleMath_Abs(C))
#define SimpleMath_AbsMin3(A, B, C) SimpleMath_Min3(SimpleMath_Abs(A), SimpleMath_Abs(B), SimpleMath_Abs(C))
#define SimpleMath_AbsMax4(A, B, C, D) SimpleMath_Max4(SimpleMath_Abs(A), SimpleMath_Abs(B), SimpleMath_Abs(C), SimpleMath_Abs(D))
#define SimpleMath_AbsMin4(A, B, C, D) SimpleMath_Min4(SimpleMath_Abs(A), SimpleMath_Abs(B), SimpleMath_Abs(C), SimpleMath_Abs(D))
#define SimpleMath_Radians(In) (In * SimpleMath_PI_180)
#define SimpleMath_Radiansf(In) (In * SimpleMath_PI_180_F)

#if defined(_WIN32) || defined(USE_FORCEINLINE)
#define FORCEINLINE __forceinline
#else
#define FORCEINLINE inline
#endif

using uint8  = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned long  int;
using uint64 = unsigned long  long;

using int8  = signed char;
using int16 = signed short int;
using int32 = signed long  int;
using int64 = signed long  long;