#pragma once

class SIMPLE_FLOATVECTOR2 {
public:
	union {
		struct { float X, Y; };
		struct { float R, G; };
		float Data[2];
	};

	FORCEINLINE SIMPLE_FLOATVECTOR2() :X(0.f), Y(0.f) { }
	FORCEINLINE SIMPLE_FLOATVECTOR2(float InF) :X(InF), Y(InF) { }
	FORCEINLINE SIMPLE_FLOATVECTOR2(float InX, float InY) :X(InX), Y(InY) { }
	FORCEINLINE SIMPLE_FLOATVECTOR2(CONST SIMPLE_FLOATVECTOR2 & In) : X(In.X), Y(In.Y) { }


	FORCEINLINE SIMPLE_FLOATVECTOR2 operator=(CONST SIMPLE_FLOATVECTOR2 REFERENCE In) { X = In.X; Y = In.Y; return *this; }

	FORCEINLINE SIMPLE_FLOATVECTOR2 operator()(CONST float REFERENCE InF) { X = InF; Y = InF; return *this; }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator()(CONST float REFERENCE InX, CONST float REFERENCE InY, CONST float REFERENCE InZ) { X = InX; Y = InY; return *this; }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator()(CONST SIMPLE_FLOATVECTOR2 & In) { X = In.X; Y = In.Y; return *this; }
	//������
	FORCEINLINE float operator^(CONST SIMPLE_FLOATVECTOR2 REFERENCE V) { return X*V.Y - Y*V.X; }
	//������
	FORCEINLINE float operator%(CONST SIMPLE_FLOATVECTOR2 REFERENCE V) { return X*V.X + Y*V.Y; }

	FORCEINLINE SIMPLE_FLOATVECTOR2 operator+(CONST SIMPLE_FLOATVECTOR2 REFERENCE V) CONST { return SIMPLE_FLOATVECTOR2(X + V.X, Y + V.Y); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator-(CONST SIMPLE_FLOATVECTOR2 REFERENCE V) CONST { return SIMPLE_FLOATVECTOR2(X - V.X, Y - V.Y); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator*(CONST SIMPLE_FLOATVECTOR2 REFERENCE V) CONST { return SIMPLE_FLOATVECTOR2(X * V.X, Y * V.Y); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator/(CONST SIMPLE_FLOATVECTOR2 REFERENCE V) CONST { return SIMPLE_FLOATVECTOR2(X / V.X, Y / V.Y); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator+(CONST float REFERENCE Bias) CONST { return SIMPLE_FLOATVECTOR2(X + Bias, Y + Bias); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator-(CONST float REFERENCE Bias) CONST { return SIMPLE_FLOATVECTOR2(X - Bias, Y - Bias); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator*(CONST float REFERENCE Scale) CONST { return SIMPLE_FLOATVECTOR2(X * Scale, Y * Scale); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator/(CONST float REFERENCE Scale) CONST { return SIMPLE_FLOATVECTOR2(X / Scale, Y / Scale); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator-() CONST { return SIMPLE_FLOATVECTOR2(-X, -Y); }

	FORCEINLINE SIMPLE_FLOATVECTOR2 operator+=(CONST SIMPLE_FLOATVECTOR2 REFERENCE V) { return SIMPLE_FLOATVECTOR2(X += V.X, Y += V.Y); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator-=(CONST SIMPLE_FLOATVECTOR2 REFERENCE V) { return SIMPLE_FLOATVECTOR2(X -= V.X, Y -= V.Y); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator*=(CONST SIMPLE_FLOATVECTOR2 REFERENCE V) { return SIMPLE_FLOATVECTOR2(X *= V.X, Y *= V.Y); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator/=(CONST SIMPLE_FLOATVECTOR2 REFERENCE V) { return SIMPLE_FLOATVECTOR2(X /= V.X, Y /= V.Y); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator+=(CONST float REFERENCE Bias) { return SIMPLE_FLOATVECTOR2(X += Bias, Y += Bias); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator-=(CONST float REFERENCE Bias) { return SIMPLE_FLOATVECTOR2(X -= Bias, Y -= Bias); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator*=(CONST float REFERENCE Scale) { return SIMPLE_FLOATVECTOR2(X *= Scale, Y *= Scale); }
	FORCEINLINE SIMPLE_FLOATVECTOR2 operator/=(CONST float REFERENCE Scale) { return SIMPLE_FLOATVECTOR2(X /= Scale, Y /= Scale); }

	FORCEINLINE float& operator[](CONST unsigned char REFERENCE Index) { return Data[Index]; }

	FORCEINLINE float& GetMin() { return SimpleMath_Min2(X, Y); }
	FORCEINLINE float& GetMax() { return SimpleMath_Max2(X, Y); }
	FORCEINLINE float GetAbsMin() CONST { return SimpleMath_AbsMin2(X, Y); }
	FORCEINLINE float GetAbsMax() CONST { return SimpleMath_AbsMax2(X, Y); }

	FORCEINLINE float Length() CONST { return sqrtf(X*X + Y*Y); }
	FORCEINLINE float LengthSquared() CONST { return X*X + Y*Y; }

	FORCEINLINE void Normalize(float Tolerance = DEFAULT_FLOAT_TOLERANCE) { float Length = X*X + Y*Y; if(Length <= Tolerance) { X = 0.f; Y = 0.f; return; }Length = sqrtf(Length); X /= Length; Y /= Length; }
	FORCEINLINE SIMPLE_FLOATVECTOR2 GetNormalized(float Tolerance = DEFAULT_FLOAT_TOLERANCE) {
		float Length = X*X + Y*Y;
		if(Length <= Tolerance) return SIMPLE_FLOATVECTOR2();
		Length = sqrtf(Length);
		return SIMPLE_FLOATVECTOR2(X / Length, Y / Length);
	}
}; 

class SIMPLE_DOUBLEVECTOR2 {
public:
	union {
		struct { double X, Y; };
		struct { double R, G; };
		double Data[2];
	};

	SIMPLE_DOUBLEVECTOR2() :X(0.0), Y(0.0) { }
	SIMPLE_DOUBLEVECTOR2(double InF) :X(InF), Y(InF) { }
	SIMPLE_DOUBLEVECTOR2(double InX, double InY) :X(InX), Y(InY) { }

	FORCEINLINE EXPLICIT SIMPLE_DOUBLEVECTOR2(CONST SIMPLE_FLOATVECTOR2 REFERENCE In) : X((double) In.X), Y((double) In.Y) { }
	FORCEINLINE EXPLICIT operator SIMPLE_FLOATVECTOR2() { return SIMPLE_FLOATVECTOR2((float) X, (float) Y); }

	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator=(CONST SIMPLE_FLOATVECTOR2 REFERENCE In) { X = (double) In.X; Y = (double) In.Y; return *this; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator=(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE In) { X = In.X; Y = In.Y; return *this; }

	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator()(CONST double REFERENCE InF) { X = InF; Y = InF; return *this; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator()(CONST double REFERENCE InX, CONST double REFERENCE InY, CONST double REFERENCE InZ) { X = InX; Y = InY; return *this; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator()(CONST SIMPLE_DOUBLEVECTOR2 & In) { X = In.X; Y = In.Y; return *this; }
	//������
	FORCEINLINE double operator^(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE V) { return X*V.Y - Y*V.X; }
	//������
	FORCEINLINE double operator%(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE V) { return X*V.X + Y*V.Y; }

	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator+(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE V) CONST { return SIMPLE_DOUBLEVECTOR2(X + V.X, Y + V.Y); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator-(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE V) CONST { return SIMPLE_DOUBLEVECTOR2(X - V.X, Y - V.Y); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator*(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE V) CONST { return SIMPLE_DOUBLEVECTOR2(X * V.X, Y * V.Y); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator/(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE V) CONST { return SIMPLE_DOUBLEVECTOR2(X / V.X, Y / V.Y); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator+(CONST double REFERENCE Bias) CONST { return SIMPLE_DOUBLEVECTOR2(X + Bias, Y + Bias); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator-(CONST double REFERENCE Bias) CONST { return SIMPLE_DOUBLEVECTOR2(X - Bias, Y - Bias); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator*(CONST double REFERENCE Scale) CONST { return SIMPLE_DOUBLEVECTOR2(X * Scale, Y * Scale); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator/(CONST double REFERENCE Scale) CONST { return SIMPLE_DOUBLEVECTOR2(X / Scale, Y / Scale); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator-() CONST { return SIMPLE_DOUBLEVECTOR2(-X, -Y); }

	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator+=(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE V) { return SIMPLE_DOUBLEVECTOR2(X += V.X, Y += V.Y); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator-=(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE V) { return SIMPLE_DOUBLEVECTOR2(X -= V.X, Y -= V.Y); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator*=(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE V) { return SIMPLE_DOUBLEVECTOR2(X *= V.X, Y *= V.Y); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator/=(CONST SIMPLE_DOUBLEVECTOR2 REFERENCE V) { return SIMPLE_DOUBLEVECTOR2(X /= V.X, Y /= V.Y); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator+=(CONST double REFERENCE Bias) { return SIMPLE_DOUBLEVECTOR2(X += Bias, Y += Bias); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator-=(CONST double REFERENCE Bias) { return SIMPLE_DOUBLEVECTOR2(X -= Bias, Y -= Bias); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator*=(CONST double REFERENCE Scale) { return SIMPLE_DOUBLEVECTOR2(X *= Scale, Y *= Scale); }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 operator/=(CONST double REFERENCE Scale) { return SIMPLE_DOUBLEVECTOR2(X /= Scale, Y /= Scale); }

	FORCEINLINE double& operator[](CONST unsigned char REFERENCE Index) { return Data[Index]; }

	FORCEINLINE double& GetMin() { return SimpleMath_Min2(X, Y); }
	FORCEINLINE double& GetMax() { return SimpleMath_Max2(X, Y); }
	FORCEINLINE double GetAbsMin() CONST { return SimpleMath_AbsMin2(X, Y); }
	FORCEINLINE double GetAbsMax() CONST { return SimpleMath_AbsMax2(X, Y); }

	FORCEINLINE double Length() CONST { return sqrt(X*X + Y*Y); }
	FORCEINLINE double LengthSquared() CONST { return X*X + Y*Y; }

	FORCEINLINE void Normalize(double Tolerance = DEFAULT_DOUBLE_TOLERANCE) { double Length = X*X + Y*Y; if(Length <= Tolerance) { X = 0.0; Y = 0.0; return; }Length = sqrt(Length); X /= Length; Y /= Length; }
	FORCEINLINE SIMPLE_DOUBLEVECTOR2 GetNormalized(double Tolerance = DEFAULT_DOUBLE_TOLERANCE) {
		double Length = X*X + Y*Y;
		if(Length <= Tolerance) return SIMPLE_DOUBLEVECTOR2();
		Length = sqrt(Length);
		return SIMPLE_DOUBLEVECTOR2(X / Length, Y / Length);
	}
};