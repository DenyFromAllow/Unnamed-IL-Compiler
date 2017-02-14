#pragma once

class VarType {
public:
	enum TypeEnum :uint32 {
		null = 0,
		none = null,
		i8, b = i8,
		i16, w = i16,
		i32, d = i32,
		i64, q = i64,
		i128,
		i256,
		f,
		df,
		ld,
		ptr = 0x0F,
		error = (uint32) -1
	};
};