#pragma once

class  SIMPLE_FLOATMATRIX4 {
public:
	union {
		float Data[16];
		float Data2D[4][4];
		SIMPLE_FLOATVECTOR4 DataV[4];
	};

	static const SIMPLE_FLOATMATRIX4 identity;

	FORCEINLINE SIMPLE_FLOATMATRIX4() : Data{
		0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	} { }

	FORCEINLINE SIMPLE_FLOATMATRIX4(
		CONST float REFERENCE In0,  CONST float REFERENCE In1,  CONST float REFERENCE In2,  CONST float REFERENCE In3, 
		CONST float REFERENCE In4,  CONST float REFERENCE In5,  CONST float REFERENCE In6,  CONST float REFERENCE In7, 
		CONST float REFERENCE In8,  CONST float REFERENCE In9,  CONST float REFERENCE In10, CONST float REFERENCE In11, 
		CONST float REFERENCE In12, CONST float REFERENCE In13, CONST float REFERENCE In14, CONST float REFERENCE In15
		) : Data{
		In0,  In1,  In2,  In3,
		In4,  In5,  In6,  In7,
		In8,  In9,  In10, In11,
		In12, In13, In14, In15
	} { }

	FORCEINLINE SIMPLE_FLOATMATRIX4(CONST float REFERENCE InF) : Data{
		InF, 0.f, 0.f, 0.f,
		0.f, InF, 0.f, 0.f,
		0.f, 0.f, InF, 0.f,
		0.f, 0.f, 0.f, InF
	} { }

	FORCEINLINE SIMPLE_FLOATMATRIX4(CONST float In[]) : Data{
		In[0],  In[1],  In[2],  In[3],
		In[4],  In[5],  In[6],  In[7],
		In[8],  In[9],  In[10], In[11],
		In[12], In[13], In[14], In[15],
	} { }

	FORCEINLINE SIMPLE_FLOATMATRIX4(
		CONST SIMPLE_FLOATVECTOR4 REFERENCE In0,
		CONST SIMPLE_FLOATVECTOR4 REFERENCE In1,
		CONST SIMPLE_FLOATVECTOR4 REFERENCE In2,
		CONST SIMPLE_FLOATVECTOR4 REFERENCE In3
		) : Data{
		In0.X, In0.Y, In0 .Z, In0.W,
		In1.X, In1.Y, In1 .Z, In1.W,
		In2.X, In2.Y, In2 .Z, In2.W,
		In3.X, In3.Y, In3 .Z, In3.W,
	} { }

	FORCEINLINE SIMPLE_FLOATMATRIX4(CONST SIMPLE_FLOATVECTOR4 In[]) : Data{
		In[0].X, In[0].Y, In[0].Z, In[0].W,
		In[1].X, In[1].Y, In[1].Z, In[1].W,
		In[2].X, In[2].Y, In[2].Z, In[2].W,
		In[3].X, In[3].Y, In[3].Z, In[3].W,
	} { }

	FORCEINLINE SIMPLE_FLOATMATRIX4(CONST SIMPLE_FLOATMATRIX4 & In) : Data{
		In.Data[0],  In.Data[1],  In.Data[3],  In.Data[4],
		In.Data[4],  In.Data[5],  In.Data[6],  In.Data[7],
		In.Data[8],  In.Data[9],  In.Data[10], In.Data[11],
		In.Data[12], In.Data[13], In.Data[14], In.Data[15],
	} { }

	FORCEINLINE SIMPLE_FLOATMATRIX4 operator=(CONST SIMPLE_FLOATMATRIX4 REFERENCE In) {
		Data[0]  = In.Data[0];  Data[1]  = In.Data[1];  Data[2]  = In.Data[2];  Data[3]  = In.Data[3];
		Data[4]  = In.Data[4];  Data[5]  = In.Data[5];  Data[6]  = In.Data[6];  Data[7]  = In.Data[7];
		Data[8]  = In.Data[8];  Data[9]  = In.Data[9];  Data[10] = In.Data[10]; Data[11] = In.Data[11];
		Data[12] = In.Data[12]; Data[13] = In.Data[13]; Data[14] = In.Data[14]; Data[15] = In.Data[15];
		return *this;
	}

	FORCEINLINE SIMPLE_FLOATMATRIX4 operator*(CONST SIMPLE_FLOATMATRIX4 REFERENCE M) {
		return SIMPLE_FLOATMATRIX4(
			Data[0]  * M.Data[0]  + Data[1]  * M.Data[4]  + Data[2]  * M.Data[8]  + Data[3]  * M.Data[12],
			Data[0]  * M.Data[1]  + Data[1]  * M.Data[5]  + Data[2]  * M.Data[9]  + Data[3]  * M.Data[13],
			Data[0]  * M.Data[2]  + Data[1]  * M.Data[6]  + Data[2]  * M.Data[10] + Data[3]  * M.Data[14],
			Data[0]  * M.Data[3]  + Data[1]  * M.Data[7]  + Data[2]  * M.Data[11] + Data[3]  * M.Data[15],
			
			Data[4]  * M.Data[0]  + Data[5]  * M.Data[4]  + Data[6]  * M.Data[8]  + Data[7]  * M.Data[12],
			Data[4]  * M.Data[1]  + Data[5]  * M.Data[5]  + Data[6]  * M.Data[9]  + Data[7]  * M.Data[13],
			Data[4]  * M.Data[2]  + Data[5]  * M.Data[6]  + Data[6]  * M.Data[10] + Data[7]  * M.Data[14],
			Data[4]  * M.Data[3]  + Data[5]  * M.Data[7]  + Data[6]  * M.Data[11] + Data[7]  * M.Data[15],
			
			Data[8]  * M.Data[0]  + Data[9]  * M.Data[4]  + Data[10] * M.Data[8]  + Data[11] * M.Data[12],
			Data[8]  * M.Data[1]  + Data[9]  * M.Data[5]  + Data[10] * M.Data[9]  + Data[11] * M.Data[13],
			Data[8]  * M.Data[2]  + Data[9]  * M.Data[6]  + Data[10] * M.Data[10] + Data[11] * M.Data[14],
			Data[8]  * M.Data[3]  + Data[9]  * M.Data[7]  + Data[10] * M.Data[11] + Data[11] * M.Data[15],
			
			Data[12] * M.Data[0]  + Data[13] * M.Data[4]  + Data[14] * M.Data[8]  + Data[15] * M.Data[12],
			Data[12] * M.Data[1]  + Data[13] * M.Data[5]  + Data[14] * M.Data[9]  + Data[15] * M.Data[13],
			Data[12] * M.Data[2]  + Data[13] * M.Data[6]  + Data[14] * M.Data[10] + Data[15] * M.Data[14],
			Data[12] * M.Data[3]  + Data[13] * M.Data[7]  + Data[14] * M.Data[11] + Data[15] * M.Data[15]
			);
	}

	FORCEINLINE SIMPLE_FLOATMATRIX4 operator*=(CONST SIMPLE_FLOATMATRIX4 REFERENCE M) {
		return (*this) = (*this)*M;
	}


};

FORCEINLINE  SIMPLE_FLOATVECTOR4 operator*(CONST SIMPLE_FLOATVECTOR4 REFERENCE V, CONST SIMPLE_FLOATMATRIX4 REFERENCE M) {
	return SIMPLE_FLOATVECTOR4(
		V.X * M.Data[0] + V.Y * M.Data[4] + V.Z * M.Data[8]  + V.W * M.Data[12],
		V.X * M.Data[1] + V.Y * M.Data[5] + V.Y * M.Data[9]  + V.W * M.Data[13],
		V.X * M.Data[2] + V.Y * M.Data[6] + V.Y * M.Data[10] + V.W * M.Data[14],
		V.X * M.Data[3] + V.Y * M.Data[7] + V.Y * M.Data[11] + V.W * M.Data[15]
		);
}

class SIMPLE_DOUBLEMATRIX4 {
public:
	union {
		double Data[16];
		double Data2D[4][4];
		SIMPLE_DOUBLEVECTOR4 DataV;
	};

	static const SIMPLE_DOUBLEMATRIX4 identity;

	FORCEINLINE SIMPLE_DOUBLEMATRIX4() : Data{
		0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f
	} { }

	FORCEINLINE SIMPLE_DOUBLEMATRIX4(
		CONST double REFERENCE In0, CONST double REFERENCE In1, CONST double REFERENCE In2, CONST double REFERENCE In3,
		CONST double REFERENCE In4, CONST double REFERENCE In5, CONST double REFERENCE In6, CONST double REFERENCE In7,
		CONST double REFERENCE In8, CONST double REFERENCE In9, CONST double REFERENCE In10, CONST double REFERENCE In11,
		CONST double REFERENCE In12, CONST double REFERENCE In13, CONST double REFERENCE In14, CONST double REFERENCE In15
		) : Data{
		In0,  In1,  In2,  In3,
		In4,  In5,  In6,  In7,
		In8,  In9,  In10, In11,
		In12, In13, In14, In15
	} { }

	FORCEINLINE SIMPLE_DOUBLEMATRIX4(CONST double REFERENCE InF) : Data{
		InF, 0.f, 0.f, 0.f,
		0.f, InF, 0.f, 0.f,
		0.f, 0.f, InF, 0.f,
		0.f, 0.f, 0.f, InF
	} { }

	FORCEINLINE SIMPLE_DOUBLEMATRIX4(CONST double In[]) : Data{
		In[0],  In[1],  In[2],  In[3],
		In[4],  In[5],  In[6],  In[7],
		In[8],  In[9],  In[10], In[11],
		In[12], In[13], In[14], In[15],
	} { }

	FORCEINLINE SIMPLE_DOUBLEMATRIX4(
		CONST SIMPLE_DOUBLEVECTOR4 REFERENCE In0,
		CONST SIMPLE_DOUBLEVECTOR4 REFERENCE In1,
		CONST SIMPLE_DOUBLEVECTOR4 REFERENCE In2,
		CONST SIMPLE_DOUBLEVECTOR4 REFERENCE In3
		) : Data{
		In0.X, In0.Y, In0.Z, In0.W,
		In1.X, In1.Y, In1.Z, In1.W,
		In2.X, In2.Y, In2.Z, In2.W,
		In3.X, In3.Y, In3.Z, In3.W,
	} { }

	FORCEINLINE SIMPLE_DOUBLEMATRIX4(CONST SIMPLE_DOUBLEVECTOR4 In[]) : Data{
		In[0].X, In[0].Y, In[0].Z, In[0].W,
		In[1].X, In[1].Y, In[1].Z, In[1].W,
		In[2].X, In[2].Y, In[2].Z, In[2].W,
		In[3].X, In[3].Y, In[3].Z, In[3].W,
	} { }

	FORCEINLINE SIMPLE_DOUBLEMATRIX4(CONST SIMPLE_DOUBLEMATRIX4 & In) : Data{
		In.Data[0],  In.Data[1],  In.Data[3],  In.Data[4],
		In.Data[4],  In.Data[5],  In.Data[6],  In.Data[7],
		In.Data[8],  In.Data[9],  In.Data[10], In.Data[11],
		In.Data[12], In.Data[13], In.Data[14], In.Data[15],
	} { }

	FORCEINLINE SIMPLE_DOUBLEMATRIX4 operator=(CONST SIMPLE_DOUBLEMATRIX4 REFERENCE In) {
		Data[0] = In.Data[0];  Data[1] = In.Data[1];  Data[2] = In.Data[2];  Data[3] = In.Data[3];
		Data[4] = In.Data[4];  Data[5] = In.Data[5];  Data[6] = In.Data[6];  Data[7] = In.Data[7];
		Data[8] = In.Data[8];  Data[9] = In.Data[9];  Data[10] = In.Data[10]; Data[11] = In.Data[11];
		Data[12] = In.Data[12]; Data[13] = In.Data[13]; Data[14] = In.Data[14]; Data[15] = In.Data[15];
		return *this;
	}

	FORCEINLINE SIMPLE_DOUBLEMATRIX4 operator*(CONST SIMPLE_DOUBLEMATRIX4 REFERENCE M) {
		return SIMPLE_DOUBLEMATRIX4(
			Data[0] * M.Data[0] + Data[1] * M.Data[4] + Data[2] * M.Data[8] + Data[3] * M.Data[12],
			Data[0] * M.Data[1] + Data[1] * M.Data[5] + Data[2] * M.Data[9] + Data[3] * M.Data[13],
			Data[0] * M.Data[2] + Data[1] * M.Data[6] + Data[2] * M.Data[10] + Data[3] * M.Data[14],
			Data[0] * M.Data[3] + Data[1] * M.Data[7] + Data[2] * M.Data[11] + Data[3] * M.Data[15],

			Data[4] * M.Data[0] + Data[5] * M.Data[4] + Data[6] * M.Data[8] + Data[7] * M.Data[12],
			Data[4] * M.Data[1] + Data[5] * M.Data[5] + Data[6] * M.Data[9] + Data[7] * M.Data[13],
			Data[4] * M.Data[2] + Data[5] * M.Data[6] + Data[6] * M.Data[10] + Data[7] * M.Data[14],
			Data[4] * M.Data[3] + Data[5] * M.Data[7] + Data[6] * M.Data[11] + Data[7] * M.Data[15],

			Data[8] * M.Data[0] + Data[9] * M.Data[4] + Data[10] * M.Data[8] + Data[11] * M.Data[12],
			Data[8] * M.Data[1] + Data[9] * M.Data[5] + Data[10] * M.Data[9] + Data[11] * M.Data[13],
			Data[8] * M.Data[2] + Data[9] * M.Data[6] + Data[10] * M.Data[10] + Data[11] * M.Data[14],
			Data[8] * M.Data[3] + Data[9] * M.Data[7] + Data[10] * M.Data[11] + Data[11] * M.Data[15],

			Data[12] * M.Data[0] + Data[13] * M.Data[4] + Data[14] * M.Data[8] + Data[15] * M.Data[12],
			Data[12] * M.Data[1] + Data[13] * M.Data[5] + Data[14] * M.Data[9] + Data[15] * M.Data[13],
			Data[12] * M.Data[2] + Data[13] * M.Data[6] + Data[14] * M.Data[10] + Data[15] * M.Data[14],
			Data[12] * M.Data[3] + Data[13] * M.Data[7] + Data[14] * M.Data[11] + Data[15] * M.Data[15]
			);
	}

	FORCEINLINE SIMPLE_DOUBLEMATRIX4 operator*=(CONST SIMPLE_DOUBLEMATRIX4 REFERENCE M) {
		return (*this) = (*this)*M;
	}


};

FORCEINLINE SIMPLE_DOUBLEVECTOR4 operator*(CONST SIMPLE_DOUBLEVECTOR4 REFERENCE V, CONST SIMPLE_DOUBLEMATRIX4 REFERENCE M) {
	return SIMPLE_DOUBLEVECTOR4(
		V.X * M.Data[0] + V.Y * M.Data[4] + V.Z * M.Data[8] + V.W * M.Data[12],
		V.X * M.Data[1] + V.Y * M.Data[5] + V.Y * M.Data[9] + V.W * M.Data[13],
		V.X * M.Data[2] + V.Y * M.Data[6] + V.Y * M.Data[10] + V.W * M.Data[14],
		V.X * M.Data[3] + V.Y * M.Data[7] + V.Y * M.Data[11] + V.W * M.Data[15]
		);
}