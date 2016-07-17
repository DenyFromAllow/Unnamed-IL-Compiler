#pragma once

#define SimpleMath_E        2.71828182845904523536   // e
#define SimpleMath_LOG2E    1.44269504088896340736   // log2(e)
#define SimpleMath_LOG10E   0.434294481903251827651  // log10(e)
#define SimpleMath_LN2      0.693147180559945309417  // ln(2)
#define SimpleMath_LN10     2.30258509299404568402   // ln(10)
#define SimpleMath_PI       3.14159265358979323846   // pi
#define SimpleMath_PI_2     1.57079632679489661923   // pi/2
#define SimpleMath_PI_4     0.785398163397448309616  // pi/4
#define SimpleMath_PI_180   0.017453292519943295     // pi/180
#define SimpleMath_1_PI     0.318309886183790671538  // 1/pi
#define SimpleMath_2_PI     0.636619772367581343076  // 2/pi
#define SimpleMath_2_SQRTPI 1.12837916709551257390   // 2/sqrt(pi)
#define SimpleMath_SQRT2    1.41421356237309504880   // sqrt(2)
#define SimpleMath_SQRT1_2  0.707106781186547524401  // 1/sqrt(2)
#define SimpleMath_E_F        2.71828182845904523536f   // e
#define SimpleMath_LOG2E_F    1.44269504088896340736f   // log2(e)
#define SimpleMath_LOG10E_F   0.434294481903251827651f  // log10(e)
#define SimpleMath_LN2_F      0.693147180559945309417f  // ln(2)
#define SimpleMath_LN10_F     2.30258509299404568402f   // ln(10)
#define SimpleMath_PI_F       3.14159265358979323846f   // pi
#define SimpleMath_PI_2_F     1.57079632679489661923f   // pi/2
#define SimpleMath_PI_4_F     0.785398163397448309616f  // pi/4
#define SimpleMath_PI_180_F   0.017453292519943295f     // pi/180
#define SimpleMath_1_PI_F     0.318309886183790671538f  // 1/pi
#define SimpleMath_2_PI_F     0.636619772367581343076f  // 2/pi
#define SimpleMath_2_SQRTPI_F 1.12837916709551257390f   // 2/sqrt(pi)
#define SimpleMath_SQRT2_F    1.41421356237309504880f   // sqrt(2)
#define SimpleMath_SQRT1_2_F  0.707106781186547524401f  // 1/sqrt(2)

#define DEFAULT_FLOAT_TOLERANCE (1.e-6f)
#define BIG_FLOAT_TOLERANCE (1.e-4f)
#define SMALL_FLOAT_TOLERANCE (1.e-8f)

#define DEFAULT_DOUBLE_TOLERANCE (1.e-10)
#define BIG_DOUBLE_TOLERANCE (1.e-6)
#define SMALL_DOUBLE_TOLERANCE (1.e-16)

#include "MathUtility/MathUtility.h"
#include "Largeinteger/int128.h"
#include "LinearAlgebra/Vector2.h"
#include "LinearAlgebra/Vector3.h"
#include "LinearAlgebra/Vector4.h"
#include "LinearAlgebra/Matrix4.h"
#include "Rotator/EulerAngle.h"

SIMPLE_FLOATMATRIX4 RotationMatrix(SIMPLE_FLOATEULARANGLE Rotation);
SIMPLE_FLOATMATRIX4 TranslationMatrix(SIMPLE_FLOATVECTOR3 Location);
SIMPLE_FLOATMATRIX4 ScaleMatrix(SIMPLE_FLOATVECTOR3 Scale);

SIMPLE_DOUBLEMATRIX4 RotationMatrix(SIMPLE_DOUBLEEULARANGLE Rotation);
SIMPLE_DOUBLEMATRIX4 TranslationMatrix(SIMPLE_DOUBLEVECTOR3 Location);
SIMPLE_DOUBLEMATRIX4 ScaleMatrix(SIMPLE_DOUBLEVECTOR3 Scale);
