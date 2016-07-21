#include <iostream>
#include <fstream>
#include <vector>
#include "main.h"
using namespace std;

SIMPLE_TRIETREE MainTrie;
ofstream OutFile;
SIMPLE_TEXTREADER *SourceReader;
AArray<Variable> Stack, Memory;
tempVariable* tempVariableList = nullptr;
bool InProc = false;

int main() {
	InitInstructions();

	ifstream SourceFile("source",ios::binary);
	SourceFile.seekg(0, ios::end);
	uint64 filesize = SourceFile.tellg();
	char*InFile = new char[filesize + 1];
	SourceFile.seekg(0, ios::beg);
	SourceFile.read(InFile, filesize);
	InFile[filesize] = 0;

	SIMPLE_TEXTREADER source_reader(InFile);
	delete[]InFile;
	SourceReader = &source_reader;
	InitReader();

	ofstream TempFile("TEMPFILE");
	String SourceString;
	while(1) {
		check();
		source_reader.ReadWord(SourceString);
		SourceString.ToLowerCase();
		int32 Instruction = MainTrie.findPrefix(SourceString.begin());
		if(!Instruction) {
			if(SourceString.IsEmpty()) {
				SourceString = ".....";
			}
			SourceString++;
			_getch();
			return 0;
		}
		if(Instruction == 0xD0 || Instruction == 0xD1)Ram(Instruction, SourceString);
		if(source_reader.EndOfText()) {
			printf("∂¡»°Ω· ¯°£");
			_getch();
			return 0;
		}
	}

	return 0;
}