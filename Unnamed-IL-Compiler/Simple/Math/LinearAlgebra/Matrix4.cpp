#include "../../simple.h"

SIMPLE_FLOATMATRIX4 RotationMatrix(SIMPLE_FLOATEULARANGLE Rotation) {
	float SinTemp = sinf(SimpleMath_Radiansf(Rotation.Yaw));
	float CosTemp = cosf(SimpleMath_Radiansf(Rotation.Yaw));
	SIMPLE_FLOATMATRIX4 result(
		CosTemp,  SinTemp,  0.f,      0.f,
		-SinTemp, CosTemp,  0.f,      0.f,
		0.f,      0.f,      1.f,      0.f,
		0.f,      0.f,      0.f,      1.f
		);
	SinTemp = sinf(SimpleMath_Radiansf(Rotation.Pitch));
	CosTemp = cosf(SimpleMath_Radiansf(Rotation.Pitch));
	result *= SIMPLE_FLOATMATRIX4(
		CosTemp,  0.f,      SinTemp,  0.f,
		0.f,      1.f,      0.f,      0.f,
		-SinTemp, 0.f,      CosTemp,  0.f,
		0.f,      0.f,      0.f,      1.f
		);
	SinTemp = sinf(SimpleMath_Radiansf(Rotation.Roll));
	CosTemp = cosf(SimpleMath_Radiansf(Rotation.Roll));
	result *= SIMPLE_FLOATMATRIX4(
		1.f,      0.f,      0.f,      0.f,
		0.f,      CosTemp,  -SinTemp, 0.f,
		0.f,      SinTemp,  CosTemp,  0.f,
		0.f,      0.f,      0.f,      0.f
		);
	return result;
}

SIMPLE_FLOATMATRIX4 TranslationMatrix(SIMPLE_FLOATVECTOR3 Location) {
	return SIMPLE_FLOATMATRIX4(
		1.f,           0.f,           0.f,           0.f,
		0.f,           1.f,           0.f,           0.f,
		0.f,           0.f,           1.f,           0.f,
		Location.X,    Location.Y,    Location.Z,    1.f
		);
}

SIMPLE_FLOATMATRIX4 ScaleMatrix(SIMPLE_FLOATVECTOR3 Scale) {
	return SIMPLE_FLOATMATRIX4(
		Scale.X,  0.f,      0.f,      0.f,
		0.f,      Scale.Y,  0.f,      0.f,
		0.f,      0.f,      Scale.Z,  0.f,
		0.f,      0.f,      0.f,      1.f
		);
}

SIMPLE_DOUBLEMATRIX4 RotationMatrix(SIMPLE_DOUBLEEULARANGLE Rotation) {
	double SinTemp = sin(SimpleMath_Radians(Rotation.Yaw));
	double CosTemp = cos(SimpleMath_Radians(Rotation.Yaw));
	SIMPLE_DOUBLEMATRIX4 result(
		CosTemp, 0.f, SinTemp, 0.f,
		0.f, 1.f, 0.f, 0.f,
		-SinTemp, 0.f, CosTemp, 0.f,
		0.f, 0.f, 0.f, 1.f
		);
	SinTemp = sin(SimpleMath_Radians(Rotation.Pitch));
	CosTemp = cos(SimpleMath_Radians(Rotation.Pitch));
	result *= SIMPLE_DOUBLEMATRIX4(
		1.f, 0.f, 0.f, 0.f,
		0.f, CosTemp, SinTemp, 0.f,
		0.f, -SinTemp, CosTemp, 0.f,
		0.f, 0.f, 0.f, 1.f
		);
	SinTemp = sin(SimpleMath_Radians(Rotation.Roll));
	CosTemp = cos(SimpleMath_Radians(Rotation.Roll));
	result *= SIMPLE_DOUBLEMATRIX4(
		CosTemp, -SinTemp, 0.f, 0.f,
		SinTemp, CosTemp, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 0.f
		);
	return result;
}

SIMPLE_DOUBLEMATRIX4 TranslationMatrix(SIMPLE_DOUBLEVECTOR3 Location) {
	return SIMPLE_DOUBLEMATRIX4(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		Location.X, Location.Y, Location.Z, 1.f
		);
}

SIMPLE_DOUBLEMATRIX4 ScaleMatrix(SIMPLE_DOUBLEVECTOR3 Scale) {
	return SIMPLE_DOUBLEMATRIX4(
		Scale.X, 0.f, 0.f, 0.f,
		0.f, Scale.Y, 0.f, 0.f,
		0.f, 0.f, Scale.Z, 0.f,
		0.f, 0.f, 0.f, 1.f
		);
}
