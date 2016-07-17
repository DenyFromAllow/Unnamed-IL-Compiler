#pragma once

namespace Simple {
	template<typename ElementType>
	using AArray		= SIMPLE_TEMPLETEARRAY_AUTO<ElementType>;

	template<typename ElementType>
	using MArray		= SIMPLE_TEMPLETEARRAY_MANUAL<ElementType>;

	using ArrayLCM		= SIMPLE_TEMPLETEARRAY_LENGTH_CONTROL_MODE;

	using Time			= SIMPLE_TIME;
	using Timer			= SIMPLE_TIMER;
	using Interval		= SIMPLE_INTERVAL;
	using HPInterval	= SIMPLE_HIGH_PRECISION_INTERVAL;
	using EBInterval	= SIMPLE_EXTREMELY_BRIEF_INTERVAL;

	using FMatrix4		= SIMPLE_FLOATMATRIX4;
	using DMatrix4		= SIMPLE_DOUBLEMATRIX4;

	using FVector2		= SIMPLE_FLOATVECTOR2;
	using FVector3		= SIMPLE_FLOATVECTOR3;
	using FVector4		= SIMPLE_FLOATVECTOR4;
	using DVector2		= SIMPLE_DOUBLEVECTOR2;
	using DVector3		= SIMPLE_DOUBLEVECTOR3;
	using DVector4		= SIMPLE_DOUBLEVECTOR4;

	using FEular		= SIMPLE_FLOATEULARANGLE;
	using DEular		= SIMPLE_DOUBLEEULARANGLE;

	using String		= SIMPLE_STRING;

	FORCEINLINE void Int8ToString	(char * buffer, int8		InInt8) 	{ SimpleTP_Int8ToString	(buffer, InInt8);	}	/*»º³åÇø>=5*/
	FORCEINLINE void Int16ToString	(char * buffer, int16		InInt16)	{ SimpleTP_Int16ToString	(buffer, InInt16);	}	/*»º³åÇø>=7*/
	FORCEINLINE void Int32ToString	(char * buffer, int32		InInt32)	{ SimpleTP_Int32ToString	(buffer, InInt32);	}	/*»º³åÇø>=12*/
	FORCEINLINE void Int64ToString	(char * buffer, int64		InInt64)	{ SimpleTP_Int64ToString	(buffer, InInt64);	}	/*»º³åÇø>=21*/
	FORCEINLINE void Uint8ToString	(char * buffer, uint8		InInt8)		{ SimpleTP_Uint8ToString	(buffer, InInt8);	}	/*»º³åÇø>=4*/
	FORCEINLINE void Uint16ToString	(char * buffer, uint16		InInt16)	{ SimpleTP_Uint16ToString	(buffer, InInt16);	}	/*»º³åÇø>=6*/
	FORCEINLINE void Uint32ToString	(char * buffer, uint32		InInt32)	{ SimpleTP_Uint32ToString	(buffer, InInt32);	}	/*»º³åÇø>=11*/
	FORCEINLINE void Uint64ToString	(char * buffer, uint64		InInt64)	{ SimpleTP_Uint64ToString	(buffer, InInt64);	}	/*»º³åÇø>=21*/
	FORCEINLINE void FloatToString	(char * string, float		InFloat)	{ SimpleTP_FloatToString	(string, InFloat);	}	/*»º³åÇø>=12*/
	FORCEINLINE void DoubleToString	(char * string, double		InDouble)	{ SimpleTP_DoubleToString	(string, InDouble);	}	/*»º³åÇø>=22*/

	FORCEINLINE void Int8ToString	(char * buffer, uint8 InLength, int8	InInt8)		{ SimpleTP_Int8ToString	(buffer, InLength, InInt8);	}	/*»º³åÇø>=5  && »º³åÇø>=InLength*/
	FORCEINLINE void Int16ToString	(char * buffer, uint8 InLength, int16	InInt16)	{ SimpleTP_Int16ToString	(buffer, InLength, InInt16);}	/*»º³åÇø>=7  && »º³åÇø>=InLength*/
	FORCEINLINE void Int32ToString	(char * buffer, uint8 InLength, int32	InInt32)	{ SimpleTP_Int32ToString	(buffer, InLength, InInt32);}	/*»º³åÇø>=12 && »º³åÇø>=InLength*/
	FORCEINLINE void Int64ToString	(char * buffer, uint8 InLength, int64	InInt64)	{ SimpleTP_Int64ToString	(buffer, InLength, InInt64);}	/*»º³åÇø>=21 && »º³åÇø>=InLength*/
	FORCEINLINE void Uint8ToString	(char * buffer, uint8 InLength, uint8	InInt8)		{ SimpleTP_Uint8ToString	(buffer, InLength, InInt8);	}	/*»º³åÇø>=4  && »º³åÇø>=InLength*/
	FORCEINLINE void Uint16ToString	(char * buffer, uint8 InLength, uint16	InInt16)	{ SimpleTP_Uint16ToString	(buffer, InLength, InInt16);}	/*»º³åÇø>=6  && »º³åÇø>=InLength*/
	FORCEINLINE void Uint32ToString	(char * buffer, uint8 InLength, uint32	InInt32)	{ SimpleTP_Uint32ToString	(buffer, InLength, InInt32);}	/*»º³åÇø>=11 && »º³åÇø>=InLength*/
	FORCEINLINE void Uint64ToString	(char * buffer, uint8 InLength, uint64	InInt64)	{ SimpleTP_Uint64ToString	(buffer, InLength, InInt64);}	/*»º³åÇø>=21 && »º³åÇø>=InLength*/
}