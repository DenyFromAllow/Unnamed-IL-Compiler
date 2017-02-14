#include "main.h"

void InitInstructions() {
	MainTrie.add("add", 0x01);
	MainTrie.add("adc", 0x02);
	MainTrie.add("sub", 0x03);
	MainTrie.add("sbb", 0x04);
	MainTrie.add("mul", 0x05);
	MainTrie.add("imul", 0x06);
	MainTrie.add("div", 0x07);
	MainTrie.add("idiv", 0x08);
	MainTrie.add("rem", 0x09);
	MainTrie.add("cmp", 0x0A);
	MainTrie.add("inc", 0x0B);
	MainTrie.add("dec", 0x0C);
	MainTrie.add("nec", 0x0D);

	MainTrie.add("and", 0x0E);
	MainTrie.add("or", 0x0F);
	MainTrie.add("not", 0x10);
	MainTrie.add("xor", 0x11);
	MainTrie.add("shl", 0x12);
	MainTrie.add("shr", 0x13);
	MainTrie.add("sal", 0x14);
	MainTrie.add("sar", 0x15);
	MainTrie.add("rol", 0x16);
	MainTrie.add("ror", 0x17);
	MainTrie.add("rcl", 0x18);
	MainTrie.add("rcr", 0x19);
	MainTrie.add("test", 0x1A);

	MainTrie.add("mov", 0x20);
	MainTrie.add("movsx", 0x21);
	MainTrie.add("movzx", 0x22);
	MainTrie.add("xchg", 0x23);

	MainTrie.add("call", 0x28);
	MainTrie.add("ret", 0x29);
	MainTrie.add("jmp", 0x2A);
	MainTrie.add("ja", 0x2B); MainTrie.add("jnbe", 0x2B);
	MainTrie.add("jb", 0x2C); MainTrie.add("jnae", 0x2C);
	MainTrie.add("jg", 0x2D); MainTrie.add("jnle", 0x2D);
	MainTrie.add("jl", 0x2E); MainTrie.add("jnge", 0x2E);
	MainTrie.add("jae", 0x2F); MainTrie.add("jnb", 0x2F);
	MainTrie.add("jbe", 0x30); MainTrie.add("jna", 0x30);
	MainTrie.add("jge", 0x31); MainTrie.add("jnl", 0x31);
	MainTrie.add("jle", 0x32); MainTrie.add("jng", 0x32);
	MainTrie.add("je", 0x33); MainTrie.add("jz", 0x33);
	MainTrie.add("jne", 0x34); MainTrie.add("jnz", 0x34);
	MainTrie.add("js", 0x35);
	MainTrie.add("jns", 0x36);
	MainTrie.add("jc", 0x37);
	MainTrie.add("jnc", 0x38);
	MainTrie.add("jo", 0x39);
	MainTrie.add("jno", 0x3A);
	MainTrie.add("jp", 0x3B); MainTrie.add("jpe", 0x3B);
	MainTrie.add("jnp", 0x3C); MainTrie.add("jpo", 0x3C);

	MainTrie.add("dot", 0x8C);
	MainTrie.add("cross", 0x8F);

	MainTrie.add("movs", 0xA1);
	MainTrie.add("stos", 0xA2);

	MainTrie.add("reg", 0xA3);

	MainTrie.add("pop", 0xD2);
	MainTrie.add("temp", 0xD3);
	MainTrie.add("proc", 0xD4);

	MainTrie.add("free", 0x101);
}

void InitTypes() {
	TypeTrie.add("i8", VarType::i8); TypeTrie.add("byte", VarType::i8);
	TypeTrie.add("i16", VarType::i16); TypeTrie.add("word", VarType::i16);
	TypeTrie.add("i32", VarType::i32); TypeTrie.add("dword", VarType::i32);
	TypeTrie.add("i64", VarType::i64); TypeTrie.add("qword", VarType::i64);
	TypeTrie.add("i128", VarType::i128);
	TypeTrie.add("i256", VarType::i256);
	TypeTrie.add("float", VarType::f);
	TypeTrie.add("double", VarType::df);
	TypeTrie.add("longdouble", VarType::ld); TypeTrie.add("ld", VarType::ld);
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
