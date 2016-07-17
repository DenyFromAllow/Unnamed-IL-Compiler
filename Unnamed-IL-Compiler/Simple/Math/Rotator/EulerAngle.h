#pragma once

class SIMPLE_FLOATEULARANGLE {
public:
	float Pitch, Yaw, Roll;
	
	FORCEINLINE SIMPLE_FLOATEULARANGLE() : Pitch(0.f), Yaw(0.f), Roll(0.f) { }
	FORCEINLINE SIMPLE_FLOATEULARANGLE(float InPitch, float InYaw, float InRoll) : Pitch(InPitch), Yaw(InYaw), Roll(InRoll) { }

	SIMPLE_FLOATVECTOR3 Forward();
	SIMPLE_FLOATVECTOR3 Right();
	SIMPLE_FLOATVECTOR3 Up();
	void ForwardRightUp(SIMPLE_FLOATVECTOR3 &Forward, SIMPLE_FLOATVECTOR3 &Right, SIMPLE_FLOATVECTOR3 &Up);
	operator SIMPLE_FLOATMATRIX4();
};

class SIMPLE_DOUBLEEULARANGLE {
public:
	double Pitch, Yaw, Roll;

	FORCEINLINE SIMPLE_DOUBLEEULARANGLE() : Pitch(0.f), Yaw(0.f), Roll(0.f) { }
	FORCEINLINE SIMPLE_DOUBLEEULARANGLE(double InPitch, double InYaw, double InRoll) : Pitch(InPitch), Yaw(InYaw), Roll(InRoll) { }
	FORCEINLINE SIMPLE_DOUBLEEULARANGLE(SIMPLE_FLOATEULARANGLE In) : Pitch((double) In.Pitch), Yaw((double) In.Yaw), Roll((double) In.Roll) { }
	FORCEINLINE operator SIMPLE_DOUBLEEULARANGLE() { return SIMPLE_FLOATEULARANGLE((float) Roll, (float) Pitch, (float) Yaw); }

	SIMPLE_DOUBLEVECTOR3 Forward();
	SIMPLE_DOUBLEVECTOR3 Right();
	SIMPLE_DOUBLEVECTOR3 Up();
	void ForwardRightUp(SIMPLE_DOUBLEVECTOR3 &Forward, SIMPLE_DOUBLEVECTOR3 &Right, SIMPLE_DOUBLEVECTOR3 &Up);
	operator SIMPLE_DOUBLEMATRIX4();
};