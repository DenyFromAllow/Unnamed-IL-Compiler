#pragma once

class SIMPLE_FLOATVECTOR3_REFERENCE {
private:
	float &X, &Y, &Z;
	FORCEINLINE SIMPLE_FLOATVECTOR3_REFERENCE(float &InX, float &InY, float &InZ) :X(InX), Y(InY), Z(InZ) { }
public:
	FORCEINLINE SIMPLE_FLOATVECTOR3_REFERENCE operator=(CONST SIMPLE_FLOATVECTOR3_REFERENCE REFERENCE In) { float Xtemp = In.X, Ytemp = In.Y, Ztemp = In.Z; X = Xtemp; Y = Ytemp; Z = Ztemp; return *this; }
	friend class SIMPLE_FLOATVECTOR3;
	friend class SIMPLE_FLOATVECTOR4;
};

class SIMPLE_DOUBLEVECTOR3_REFERENCE {
private:
	double &X, &Y, &Z;
	FORCEINLINE SIMPLE_DOUBLEVECTOR3_REFERENCE(double &InX, double &InY, double &InZ) :X(InX), Y(InY), Z(InZ) { }
public:
	FORCEINLINE SIMPLE_DOUBLEVECTOR3_REFERENCE operator=(CONST SIMPLE_DOUBLEVECTOR3_REFERENCE REFERENCE In) { double Xtemp = In.X, Ytemp = In.Y, Ztemp = In.Z; X = Xtemp; Y = Ytemp; Z = Ztemp; return *this; }
	friend class SIMPLE_DOUBLEVECTOR3;
	friend class SIMPLE_DOUBLEVECTOR4;
};

class SIMPLE_FLOATVECTOR3 {
public:
	union {
		struct { float X, Y, Z; };
		struct { float R, G, B; };
		float Data[3];
	};

	static const SIMPLE_FLOATVECTOR3 ZeroVector;
	static const SIMPLE_FLOATVECTOR3 UnitVector;

	FORCEINLINE SIMPLE_FLOATVECTOR3() :X(0.f), Y(0.f), Z(0.f) { }
	FORCEINLINE SIMPLE_FLOATVECTOR3(CONST float REFERENCE InF) :X(InF), Y(InF), Z(InF) { }
	FORCEINLINE SIMPLE_FLOATVECTOR3(CONST float REFERENCE InX, CONST float REFERENCE InY, CONST float REFERENCE InZ) :X(InX), Y(InY), Z(InZ) { }
	FORCEINLINE SIMPLE_FLOATVECTOR3(CONST SIMPLE_FLOATVECTOR2 REFERENCE InXY, CONST float REFERENCE InZ) :X(InXY.X), Y(InXY.Y), Z(InZ) { }
	FORCEINLINE SIMPLE_FLOATVECTOR3(CONST float REFERENCE InX, CONST SIMPLE_FLOATVECTOR2 REFERENCE InYZ) :X(InX), Y(InYZ.X), Z(InYZ.Y) { }
	FORCEINLINE SIMPLE_FLOATVECTOR3(CONST SIMPLE_FLOATVECTOR3 & In) :X(In.X), Y(In.Y), Z(In.Z) { }
	FORCEINLINE SIMPLE_FLOATVECTOR3(CONST SIMPLE_FLOATVECTOR3_REFERENCE & In) : X(In.X), Y(In.Y), Z(In.Z) { }

	FORCEINLINE EXPLICIT operator SIMPLE_FLOATVECTOR3_REFERENCE() { return SIMPLE_FLOATVECTOR3_REFERENCE(X, Y, Z); }

	FORCEINLINE SIMPLE_FLOATVECTOR3 operator=(CONST SIMPLE_FLOATVECTOR3 REFERENCE In) { X = In.X; Y = In.Y; Z = In.Z; return *this; }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator=(CONST SIMPLE_FLOATVECTOR3_REFERENCE REFERENCE In) { float Xtemp = In.X, Ytemp = In.Y, Ztemp = In.Z; X = Xtemp; Y = Ytemp; Z = Ztemp; return *this; }
	//向量积
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator^(CONST SIMPLE_FLOATVECTOR3 REFERENCE V) { return SIMPLE_FLOATVECTOR3(Y * V.Z - Z * V.Y, Z * V.X - X * V.Z, X * V.Y - Y * V.X); }
	//标量积
	FORCEINLINE float operator%(CONST SIMPLE_FLOATVECTOR3 REFERENCE V) { return X*V.X + Y*V.Y + Z*V.Z; }

	FORCEINLINE SIMPLE_FLOATVECTOR3 operator()(CONST float REFERENCE InF) { X = InF; Y = InF; Z = InF; return *this; }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator()(CONST float REFERENCE InX, CONST float REFERENCE InY, CONST float REFERENCE InZ) { X = InX; Y = InY; Z = InZ; return *this; }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator()(CONST SIMPLE_FLOATVECTOR2 REFERENCE InXY, CONST float REFERENCE InZ) { X = InXY.X; Y = InXY.Y; Z = InZ; return *this; }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator()(CONST float REFERENCE InX, CONST SIMPLE_FLOATVECTOR2 REFERENCE InYZ) { X = InX; Y = InYZ.X; Z = InYZ.Y; return *this; }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator()(CONST SIMPLE_FLOATVECTOR3 & In) { X = In.X; Y = In.Y; Z = In.Z; return *this; }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator()(CONST SIMPLE_FLOATVECTOR3_REFERENCE & In) { float Xtemp = In.X, Ytemp = In.Y, Ztemp = In.Z; X = Xtemp; Y = Ytemp; Z = Ztemp; return *this; }

	FORCEINLINE SIMPLE_FLOATVECTOR3 operator+(CONST SIMPLE_FLOATVECTOR3 REFERENCE V) CONST { return SIMPLE_FLOATVECTOR3(X + V.X, Y + V.Y, Z + V.Z); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator-(CONST SIMPLE_FLOATVECTOR3 REFERENCE V) CONST { return SIMPLE_FLOATVECTOR3(X - V.X, Y - V.Y, Z - V.Z); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator*(CONST SIMPLE_FLOATVECTOR3 REFERENCE V) CONST { return SIMPLE_FLOATVECTOR3(X * V.X, Y * V.Y, Z * V.Z); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator/(CONST SIMPLE_FLOATVECTOR3 REFERENCE V) CONST { return SIMPLE_FLOATVECTOR3(X / V.X, Y / V.Y, Z / V.Z); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator+(CONST float REFERENCE Bias) CONST { return SIMPLE_FLOATVECTOR3(X + Bias, Y + Bias, Z + Bias); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator-(CONST float REFERENCE Bias) CONST { return SIMPLE_FLOATVECTOR3(X - Bias, Y - Bias, Z - Bias); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator*(CONST float REFERENCE Scale) CONST { return SIMPLE_FLOATVECTOR3(X * Scale, Y * Scale, Z * Scale); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator/(CONST float REFERENCE Scale) CONST { return SIMPLE_FLOATVECTOR3(X / Scale, Y / Scale, Z / Scale); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator-() CONST { return SIMPLE_FLOATVECTOR3(-X, -Y, -Z); }

	FORCEINLINE SIMPLE_FLOATVECTOR3 operator+=(CONST SIMPLE_FLOATVECTOR3 REFERENCE V) { return SIMPLE_FLOATVECTOR3(X += V.X, Y += V.Y, Z += V.Z); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator-=(CONST SIMPLE_FLOATVECTOR3 REFERENCE V) { return SIMPLE_FLOATVECTOR3(X -= V.X, Y -= V.Y, Z -= V.Z); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator*=(CONST SIMPLE_FLOATVECTOR3 REFERENCE V) { return SIMPLE_FLOATVECTOR3(X *= V.X, Y *= V.Y, Z *= V.Z); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator/=(CONST SIMPLE_FLOATVECTOR3 REFERENCE V) { return SIMPLE_FLOATVECTOR3(X /= V.X, Y /= V.Y, Z /= V.Z); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator+=(CONST float REFERENCE Bias) { return SIMPLE_FLOATVECTOR3(X += Bias, Y += Bias, Z += Bias); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator-=(CONST float REFERENCE Bias) { return SIMPLE_FLOATVECTOR3(X -= Bias, Y -= Bias, Z -= Bias); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator*=(CONST float REFERENCE Scale) { return SIMPLE_FLOATVECTOR3(X *= Scale, Y *= Scale, Z *= Scale); }
	FORCEINLINE SIMPLE_FLOATVECTOR3 operator/=(CONST float REFERENCE Scale) { return SIMPLE_FLOATVECTOR3(X /= Scale, Y /= Scale, Z /= Scale); }

	FORCEINLINE float& operator[](CONST unsigned char REFERENCE Index) { return Data[Index]; }

	FORCEINLINE float& GetMin() { return SimpleMath_Min3(X, Y, Z); }
	FORCEINLINE float& GetMax() { return SimpleMath_Max3(X, Y, Z); }
	FORCEINLINE float GetAbsMin() CONST { return SimpleMath_AbsMin3(X, Y, Z); }
	FORCEINLINE float GetAbsMax() CONST { return SimpleMath_AbsMax3(X, Y, Z); }

	FORCEINLINE float Length() CONST { return sqrtf(X*X + Y*Y + Z*Z); }
	FORCEINLINE float LengthSquared() CONST { return X*X + Y*Y + Z*Z; }

	FORCEINLINE void Normalize(float Tolerance = DEFAULT_FLOAT_TOLERANCE) {
		float Length = X*X + Y*Y + Z*Z;
		if(Length <= Tolerance) { X = 0; Y = 0; Z = 0; return; }
		Length = sqrtf(Length);
		X /= Length; Y /= Length; Z /= Length;
	}
	FORCEINLINE SIMPLE_FLOATVECTOR3 GetNormalized(float Tolerance = DEFAULT_FLOAT_TOLERANCE) {
		float Length = X*X + Y*Y + Z*Z;
		if(Length <= Tolerance) return SIMPLE_FLOATVECTOR3();
		Length = sqrtf(Length);
		return SIMPLE_FLOATVECTOR3(X / Length, Y / Length, Z / Length);
	}
	//预留
	//Rotate;

	#include "FloatVector3.enum"
};

class SIMPLE_DOUBLEVECTOR3 {
public:
	union {
		struct { double X, Y, Z; };
		struct { double R, G, B; };
		double Data[3];
	};

	static const SIMPLE_DOUBLEVECTOR3 ZeroVector;
	static const SIMPLE_DOUBLEVECTOR3 UnitVector;

	FORCEINLINE SIMPLE_DOUBLEVECTOR3() :X(0.0), Y(0.0), Z(0.0) { }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3(CONST double REFERENCE InF) :X(InF), Y(InF), Z(InF) { }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3(CONST double REFERENCE InX, CONST double REFERENCE InY, CONST double REFERENCE InZ) :X(InX), Y(InY), Z(InZ) { }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3(CONST SIMPLE_FLOATVECTOR2 REFERENCE InXY, CONST double REFERENCE InZ) :X(InXY.X), Y(InXY.Y), Z(InZ) { }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3(CONST double REFERENCE InX, CONST SIMPLE_FLOATVECTOR2 REFERENCE InYZ) :X(InX), Y(InYZ.X), Z(InYZ.Y) { }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3(CONST SIMPLE_DOUBLEVECTOR3 &In) :X(In.X), Y(In.Y), Z(In.Z) { }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3(CONST SIMPLE_DOUBLEVECTOR3_REFERENCE &In) : X(In.X), Y(In.Y), Z(In.Z) { }

	FORCEINLINE EXPLICIT SIMPLE_DOUBLEVECTOR3(CONST SIMPLE_FLOATVECTOR3 REFERENCE In) :X((double) In.X), Y((double) In.Y), Z((double) In.Z) { }
	FORCEINLINE EXPLICIT operator SIMPLE_FLOATVECTOR3() { return SIMPLE_FLOATVECTOR3((float) X, (float) Y, (float) Z); }

	FORCEINLINE EXPLICIT operator SIMPLE_DOUBLEVECTOR3_REFERENCE() { return SIMPLE_DOUBLEVECTOR3_REFERENCE(X, Y, Z); }
	
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator=(CONST SIMPLE_FLOATVECTOR3 REFERENCE In) { X = (double) In.X; Y = (double) In.Y; Z = (double) In.Z; return *this; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator=(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE In) { X = In.X; Y = In.Y; Z = In.Z; return *this; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator=(CONST SIMPLE_DOUBLEVECTOR3_REFERENCE REFERENCE In) { double Xtemp = In.X, Ytemp = In.Y, Ztemp = In.Z; X = Xtemp; Y = Ytemp; Z = Ztemp; return *this; }
	//向量积
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator^(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE V) { return SIMPLE_DOUBLEVECTOR3(Y * V.Z - Z * V.Y, Z * V.X - X * V.Z, X * V.Y - Y * V.X); }
	//标量积
	FORCEINLINE double operator%(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE V) { return X*V.X + Y*V.Y + Z*V.Z; }

	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator()(CONST double REFERENCE InF) { X = InF; Y = InF; Z = InF; return *this; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator()(CONST double REFERENCE InX, CONST double REFERENCE InY, CONST double REFERENCE InZ) { X = InX; Y = InY; Z = InZ; return *this; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator()(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE InXY, CONST double REFERENCE InZ) { X = InXY.X; Y = InXY.Y; Z = InZ; return *this; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator()(CONST double REFERENCE InX, CONST SIMPLE_DOUBLEVECTOR2 REFERENCE InYZ) { X = InX; Y = InYZ.X; Z = InYZ.Y; return *this; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator()(CONST SIMPLE_DOUBLEVECTOR3 & In) { X = In.X; Y = In.Y; Z = In.Z; return *this; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator()(CONST SIMPLE_DOUBLEVECTOR3_REFERENCE & In) { double Xtemp = In.X, Ytemp = In.Y, Ztemp = In.Z; X = Xtemp; Y = Ytemp; Z = Ztemp; return *this; }

	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator+(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE V) CONST { return SIMPLE_DOUBLEVECTOR3(X + V.X, Y + V.Y, Z + V.Z); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator-(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE V) CONST { return SIMPLE_DOUBLEVECTOR3(X - V.X, Y - V.Y, Z - V.Z); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator*(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE V) CONST { return SIMPLE_DOUBLEVECTOR3(X * V.X, Y * V.Y, Z * V.Z); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator/(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE V) CONST { return SIMPLE_DOUBLEVECTOR3(X / V.X, Y / V.Y, Z / V.Z); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator+(CONST double REFERENCE Bias) CONST { return SIMPLE_DOUBLEVECTOR3(X + Bias, Y + Bias, Z + Bias); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator-(CONST double REFERENCE Bias) CONST { return SIMPLE_DOUBLEVECTOR3(X - Bias, Y - Bias, Z - Bias); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator*(CONST double REFERENCE Scale) CONST { return SIMPLE_DOUBLEVECTOR3(X * Scale, Y * Scale, Z * Scale); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator/(CONST double REFERENCE Scale) CONST { return SIMPLE_DOUBLEVECTOR3(X / Scale, Y / Scale, Z / Scale); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator-() CONST { return SIMPLE_DOUBLEVECTOR3(-X, -Y, -Z); }

	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator+=(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE V) { return SIMPLE_DOUBLEVECTOR3(X += V.X, Y += V.Y, Z += V.Z); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator-=(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE V) { return SIMPLE_DOUBLEVECTOR3(X -= V.X, Y -= V.Y, Z -= V.Z); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator*=(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE V) { return SIMPLE_DOUBLEVECTOR3(X *= V.X, Y *= V.Y, Z *= V.Z); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator/=(CONST SIMPLE_DOUBLEVECTOR3 REFERENCE V) { return SIMPLE_DOUBLEVECTOR3(X /= V.X, Y /= V.Y, Z /= V.Z); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator+=(CONST double REFERENCE Bias) { return SIMPLE_DOUBLEVECTOR3(X += Bias, Y += Bias, Z += Bias); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator-=(CONST double REFERENCE Bias) { return SIMPLE_DOUBLEVECTOR3(X -= Bias, Y -= Bias, Z -= Bias); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator*=(CONST double REFERENCE Scale) { return SIMPLE_DOUBLEVECTOR3(X *= Scale, Y *= Scale, Z *= Scale); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 operator/=(CONST double REFERENCE Scale) { return SIMPLE_DOUBLEVECTOR3(X /= Scale, Y /= Scale, Z /= Scale); }

	FORCEINLINE double& operator[](CONST unsigned char REFERENCE Index) { return Data[Index]; }

	FORCEINLINE double& GetMin() { return SimpleMath_Min3(X, Y, Z); }
	FORCEINLINE double& GetMax() { return SimpleMath_Max3(X, Y, Z); }
	FORCEINLINE double GetAbsMin() CONST { return SimpleMath_AbsMin3(X, Y, Z); }
	FORCEINLINE double GetAbsMax() CONST { return SimpleMath_AbsMax3(X, Y, Z); }

	FORCEINLINE double Length() CONST { return sqrt(X*X + Y*Y + Z*Z); }
	FORCEINLINE double LengthSquared() CONST { return X*X + Y*Y + Z*Z; }

	FORCEINLINE void Normalize(float Tolerance = DEFAULT_FLOAT_TOLERANCE) {
		double Length = X*X + Y*Y + Z*Z;
		if(Length <= Tolerance) { X = 0.0; Y = 0.0; Z = 0.0; return; }
		Length = sqrt(Length);
		X /= Length; Y /= Length; Z /= Length;
	}
	FORCEINLINE SIMPLE_DOUBLEVECTOR3 GetNormalized(float Tolerance = DEFAULT_FLOAT_TOLERANCE) {
		double Length = X*X + Y*Y + Z*Z;
		if(Length <= Tolerance) return SIMPLE_DOUBLEVECTOR3();
		Length = sqrt(Length);
		return SIMPLE_DOUBLEVECTOR3(X / Length, Y / Length, Z / Length);
	}

	#include "DoubleVector3.enum"
};