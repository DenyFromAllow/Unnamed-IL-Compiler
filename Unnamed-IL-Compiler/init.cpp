#include "main.h"

void InitInstructions() {
	MainDict.add("add", 0x01);
	MainDict.add("adc", 0x02);
	MainDict.add("sub", 0x03);
	MainDict.add("sbb", 0x04);
	MainDict.add("mul", 0x05);
	MainDict.add("imul", 0x06);
	MainDict.add("div", 0x07);
	MainDict.add("idiv", 0x08);
	MainDict.add("rem", 0x09);
	MainDict.add("cmp", 0x0A);
	MainDict.add("inc", 0x0B);
	MainDict.add("dec", 0x0C);
	MainDict.add("nec", 0x0D);

	MainDict.add("and", 0x0E);
	MainDict.add("or", 0x0F);
	MainDict.add("not", 0x10);
	MainDict.add("xor", 0x11);
	MainDict.add("shl", 0x12);
	MainDict.add("shr", 0x13);
	MainDict.add("sal", 0x14);
	MainDict.add("sar", 0x15);
	MainDict.add("rol", 0x16);
	MainDict.add("ror", 0x17);
	MainDict.add("rcl", 0x18);
	MainDict.add("rcr", 0x19);
	MainDict.add("test", 0x1A);

	MainDict.add("mov", 0x20);
	MainDict.add("movsx", 0x21);
	MainDict.add("movzx", 0x22);
	MainDict.add("xchg", 0x23);

	MainDict.add("call", 0x28);
	MainDict.add("ret", 0x29);
	MainDict.add("jmp", 0x2A);
	MainDict.add("ja", 0x2B); MainDict.add("jnbe", 0x2B);
	MainDict.add("jb", 0x2C); MainDict.add("jnae", 0x2C);
	MainDict.add("jg", 0x2D); MainDict.add("jnle", 0x2D);
	MainDict.add("jl", 0x2E); MainDict.add("jnge", 0x2E);
	MainDict.add("jae", 0x2F); MainDict.add("jnb", 0x2F);
	MainDict.add("jbe", 0x30); MainDict.add("jna", 0x30);
	MainDict.add("jge", 0x31); MainDict.add("jnl", 0x31);
	MainDict.add("jle", 0x32); MainDict.add("jng", 0x32);
	MainDict.add("je", 0x33); MainDict.add("jz", 0x33);
	MainDict.add("jne", 0x34); MainDict.add("jnz", 0x34);
	MainDict.add("js", 0x35);
	MainDict.add("jns", 0x36);
	MainDict.add("jc", 0x37);
	MainDict.add("jnc", 0x38);
	MainDict.add("jo", 0x39);
	MainDict.add("jno", 0x3A);
	MainDict.add("jp", 0x3B); MainDict.add("jpe", 0x3B);
	MainDict.add("jnp", 0x3C); MainDict.add("jpo", 0x3C);

	MainDict.add("dot", 0x8C);
	MainDict.add("cross", 0x8F);

	MainDict.add("movs", 0xA1);
	MainDict.add("stos", 0xA2);

	MainDict.add("temp", 0xD2);
	MainDict.add("reserve", 0xD3);
	MainDict.add("proc", 0xD4); MainDict.add("func", 0xD4); MainDict.add("process", 0xD4); MainDict.add("function", 0xD4);
	MainDict.add("except", 0xD600); MainDict.add("unwind", 0xD601);
	MainDict.add("append", 0xD7); MainDict.add("appended", 0xD7); MainDict.add("addition", 0xD7); MainDict.add("additional", 0xD7);
	MainDict.add("export", 0xD8); MainDict.add("inport", 0xD9);
	MainDict.add("stack", 0xDA);
	MainDict.add("class", 0xF1);
	MainDict.add("struct", 0xF2);
	MainDict.add("enum", 0xF3);

	MainDict.add("free", 0x101);
}

void InitTypes() {
	TypeDict.add("i8", VarType::i8); TypeDict.add("byte", VarType::i8);
	TypeDict.add("i16", VarType::i16); TypeDict.add("word", VarType::i16);
	TypeDict.add("i32", VarType::i32); TypeDict.add("dword", VarType::i32);
	TypeDict.add("i64", VarType::i64); TypeDict.add("qword", VarType::i64);
	TypeDict.add("i128", VarType::i128);
	TypeDict.add("i256", VarType::i256);
	TypeDict.add("float", VarType::f);
	TypeDict.add("double", VarType::df);
	TypeDict.add("longdouble", VarType::ld); TypeDict.add("ld", VarType::ld);
}

void InitReader() {
	SourceReader->AddIgnore(' ');
	SourceReader->AddIgnore('\t');
	SourceReader->AddSeparator('\n');
	SourceReader->AddSeparator('\r');
	SourceReader->AddSeparator(';');
	SourceReader->AddSeparator(',');
	SourceReader->AddSeparator('(');
	SourceReader->AddSeparator(')');
	SourceReader->AddSeparator('[');
	SourceReader->AddSeparator(']');
	SourceReader->AddSeparator('<');
	SourceReader->AddSeparator('>');
	SourceReader->AddSeparator('{');
	SourceReader->AddSeparator('}');

	SourceReader->AddSeparator('/');

	SourceReader->AddSeparator('`');
	SourceReader->AddSeparator('~');
	SourceReader->AddSeparator('!');
	SourceReader->AddSeparator('@');
	SourceReader->AddSeparator('#');
	SourceReader->AddSeparator('$');
	SourceReader->AddSeparator('%');
	SourceReader->AddSeparator('^');
	SourceReader->AddSeparator('&');
	SourceReader->AddSeparator('*');
	SourceReader->AddSeparator('=');
	SourceReader->AddSeparator('+');
	SourceReader->AddSeparator('|');
	SourceReader->AddSeparator('\\');
	SourceReader->AddSeparator('?');
	SourceReader->AddSeparator(':');
	SourceReader->AddSeparator('\"');
	SourceReader->UsingIgnore = true;
	SourceReader->UsingSeparator = true;
}
