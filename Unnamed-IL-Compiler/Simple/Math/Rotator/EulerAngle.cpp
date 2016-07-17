#include "../../simple.h"

/*Forward = | Cosp*Cosy, Cosp*Siny, Sinp, |
Right = | Sinr*Sinp*Cosy - Cosr*Siny, Sinr*Sinp*Siny + Cosr*Cosy, -Sinr*Cosp, |
Up = | -Cosr*Sinp*Cosy - Sinr*Siny, -Cosr*Sinp*Siny + Sinr*Cosy, Cosr*Cosp |*/
SIMPLE_FLOATVECTOR3 SIMPLE_FLOATEULARANGLE::Forward() {
	float Cosp = cosf(SimpleMath_Radiansf(Pitch));
	return SIMPLE_FLOATVECTOR3(Cosp*cosf(SimpleMath_Radiansf(Yaw)), Cosp*sinf(SimpleMath_Radiansf(Yaw)), sinf(SimpleMath_Radiansf(Pitch)));
}
SIMPLE_FLOATVECTOR3 SIMPLE_FLOATEULARANGLE::Right() {
	float Siny = sinf(SimpleMath_Radiansf(Yaw)), Cosy = cosf(SimpleMath_Radiansf(Yaw)), Sinp = sinf(SimpleMath_Radiansf(Pitch)), Cosp = cosf(SimpleMath_Radiansf(Pitch)), Sinr = sinf(SimpleMath_Radiansf(Roll)), Cosr = cosf(SimpleMath_Radiansf(Roll));
	return SIMPLE_FLOATVECTOR3(Sinr*Sinp*Cosy - Cosr*Siny, Sinr*Sinp*Siny + Cosr*Cosy, -Sinr*Cosp);
}
SIMPLE_FLOATVECTOR3 SIMPLE_FLOATEULARANGLE::Up() {
	float Siny = sinf(SimpleMath_Radiansf(Yaw)), Cosy = cosf(SimpleMath_Radiansf(Yaw)), Sinp = sinf(SimpleMath_Radiansf(Pitch)), Cosp = cosf(SimpleMath_Radiansf(Pitch)), Sinr = sinf(SimpleMath_Radiansf(Roll)), Cosr = cosf(SimpleMath_Radiansf(Roll));
	return SIMPLE_FLOATVECTOR3(-Cosr*Sinp*Cosy - Sinr*Siny, -Cosr*Sinp*Siny + Sinr*Cosy, Cosr*Cosp);
}
void SIMPLE_FLOATEULARANGLE::ForwardRightUp(SIMPLE_FLOATVECTOR3 &Forward, SIMPLE_FLOATVECTOR3 &Right, SIMPLE_FLOATVECTOR3 &Up) {
	float Siny = sinf(SimpleMath_Radiansf(Yaw)), Cosy = cosf(SimpleMath_Radiansf(Yaw)), Sinp = sinf(SimpleMath_Radiansf(Pitch)), Cosp = cosf(SimpleMath_Radiansf(Pitch)), Sinr = sinf(SimpleMath_Radiansf(Roll)), Cosr = cosf(SimpleMath_Radiansf(Roll));
	Forward(Cosp*Cosy, Cosp*Siny, Sinp);
	Right(Sinr*Sinp*Cosy - Cosr*Siny, Sinr*Sinp*Siny + Cosr*Cosy, -Sinr*Cosp);
	Up(-Cosr*Sinp*Cosy - Sinr*Siny, -Cosr*Sinp*Siny + Sinr*Cosy, Cosr*Cosp);
}

SIMPLE_FLOATEULARANGLE::operator SIMPLE_FLOATMATRIX4() {
	float Siny = sinf(SimpleMath_Radiansf(Yaw)), Cosy = cosf(SimpleMath_Radiansf(Yaw)), Sinp = sinf(SimpleMath_Radiansf(Pitch)), Cosp = cosf(SimpleMath_Radiansf(Pitch)), Sinr = sinf(SimpleMath_Radiansf(Roll)), Cosr = cosf(SimpleMath_Radiansf(Roll));
	return SIMPLE_FLOATMATRIX4(
		Cosp * Cosy,						Cosp*Siny,							Sinp,			0.f,
		Sinr * Sinp * Cosy - Cosr * Siny,	Sinr * Sinp * Siny + Cosr * Cosy,	-Sinr * Cosp,	0.f,
		-Cosr * Sinp * Cosy - Sinr * Siny,	-Cosr * Sinp * Siny + Sinr * Cosy,	Cosr * Cosp,	0.f,
		0.f,								0.f,								0.f,			1.f
		);
}

SIMPLE_DOUBLEVECTOR3 SIMPLE_DOUBLEEULARANGLE::Forward() {
	double Cosp = cos(SimpleMath_Radians(Pitch));
	return SIMPLE_DOUBLEVECTOR3(Cosp*cos(SimpleMath_Radians(Yaw)), Cosp*sin(SimpleMath_Radians(Yaw)), sin(SimpleMath_Radians(Pitch)));
}
SIMPLE_DOUBLEVECTOR3 SIMPLE_DOUBLEEULARANGLE::Right() {
	double Siny = sin(SimpleMath_Radians(Yaw)), Cosy = cos(SimpleMath_Radians(Yaw)), Sinp = sin(SimpleMath_Radians(Pitch)), Cosp = cos(SimpleMath_Radians(Pitch)), Sinr = sin(SimpleMath_Radians(Roll)), Cosr = cos(SimpleMath_Radians(Roll));
	return SIMPLE_DOUBLEVECTOR3(Sinr*Sinp*Cosy - Cosr*Siny, Sinr*Sinp*Siny + Cosr*Cosy, -Sinr*Cosp);
}
SIMPLE_DOUBLEVECTOR3 SIMPLE_DOUBLEEULARANGLE::Up() {
	double Siny = sin(SimpleMath_Radians(Yaw)), Cosy = cos(SimpleMath_Radians(Yaw)), Sinp = sin(SimpleMath_Radians(Pitch)), Cosp = cos(SimpleMath_Radians(Pitch)), Sinr = sin(SimpleMath_Radians(Roll)), Cosr = cos(SimpleMath_Radians(Roll));
	return SIMPLE_DOUBLEVECTOR3(-Cosr*Sinp*Cosy - Sinr*Siny, -Cosr*Sinp*Siny + Sinr*Cosy, Cosr*Cosp);
}
void SIMPLE_DOUBLEEULARANGLE::ForwardRightUp(SIMPLE_DOUBLEVECTOR3 &Forward, SIMPLE_DOUBLEVECTOR3 &Right, SIMPLE_DOUBLEVECTOR3 &Up) {
	double Siny = sin(SimpleMath_Radians(Yaw)), Cosy = cos(SimpleMath_Radians(Yaw)), Sinp = sin(SimpleMath_Radians(Pitch)), Cosp = cos(SimpleMath_Radians(Pitch)), Sinr = sin(SimpleMath_Radians(Roll)), Cosr = cos(SimpleMath_Radians(Roll));
	Forward(Cosp*Cosy, Cosp*Siny, Sinp);
	Right(Sinr*Sinp*Cosy - Cosr*Siny, Sinr*Sinp*Siny + Cosr*Cosy, -Sinr*Cosp);
	Up(-Cosr*Sinp*Cosy - Sinr*Siny, -Cosr*Sinp*Siny + Sinr*Cosy, Cosr*Cosp);
}

SIMPLE_DOUBLEEULARANGLE::operator SIMPLE_DOUBLEMATRIX4() {
	double Siny = sin(SimpleMath_Radians(Yaw)), Cosy = cos(SimpleMath_Radians(Yaw)), Sinp = sin(SimpleMath_Radians(Pitch)), Cosp = cos(SimpleMath_Radians(Pitch)), Sinr = sin(SimpleMath_Radians(Roll)), Cosr = cos(SimpleMath_Radians(Roll));
	return SIMPLE_DOUBLEMATRIX4(
		Cosp * Cosy,						Cosp*Siny,							Sinp,			0.0,
		Sinr * Sinp * Cosy - Cosr * Siny,	Sinr * Sinp * Siny + Cosr * Cosy,	-Sinr * Cosp,	0.0,
		-Cosr * Sinp * Cosy - Sinr * Siny,	-Cosr * Sinp * Siny + Sinr * Cosy,	Cosr * Cosp,	0.0,
		0.0,								0.0,								0.0,			1.0
		);
	return SIMPLE_DOUBLEMATRIX4(
		Cosp*Cosy, Cosp*Siny, Sinp, 0.0,
		Sinr*Sinp*Cosy - Cosr*Siny, Sinr*Sinp*Siny + Cosr*Cosy, -Sinr*Cosp, 0.0,
		-Cosr*Sinp*Cosy - Sinr*Siny, -Cosr*Sinp*Siny + Sinr*Cosy, Cosr*Cosp, 0.0,
		0.0, 0.0, 0.0, 1.0
		);
}
