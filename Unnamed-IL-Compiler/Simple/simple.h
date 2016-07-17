#ifndef __SIMPLE__
	#define __SIMPLE__
	#ifdef SIMPLE_LITE
		#pragma message("包含SIMPLE前包含SIMPLE_LITE，已忽略SIMPLE")
	#else
		#define AUTO 0
		#define NO 1
		#define YES 2
		#include"config.h"
		#if defined(_MSC_VER) && IMPORT_STATIC_LIBRARY != NO
			#ifdef _DEBUG
				#ifdef _M_X64
					#pragma comment(lib,"SIMPLE-Debug-X64")
				#else
					#pragma comment(lib,"SIMPLE-Debug-X86")
				#endif
			#else
				#ifdef _M_X64
					#pragma comment(lib,"SIMPLE-X64")
				#else
					#pragma comment(lib,"SIMPLE-X86")
				#endif
			#endif
		#endif
		#undef AUTO
		#undef NO
		#undef YES
		#include "Preprocess.h"
		#include "CrossPlatformAndUtility/CrossPlatformAndUtility.h"
		#include "TextProcessing/TextProcessing.h"
		#include "Math/Math.h"
		#include "ShortName.h"
	#endif
#endif