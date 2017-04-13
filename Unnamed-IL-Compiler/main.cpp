#include <iostream>
#include <fstream>
#include <vector>
#include "main.h"
using namespace std;

SIMPLE_TRIETREE MainTrie;
SIMPLE_TRIETREE TypeTrie;
ofstream OutFile;
SIMPLE_TEXTREADER *SourceReader;
tempVariable* tempVariableList = nullptr;
Block *currentBlock = nullptr;

int main() {
	InitInstructions();
	InitTypes();

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
	String LowerSourceString;
	while(1) {
		check();
		source_reader.ReadWord(SourceString);
		LowerSourceString = SourceString;
		LowerSourceString.ToLowerCase();
		uint32 Instruction = MainTrie.findPrefix(LowerSourceString.begin());
		if(!Instruction) {
			uint32 type = ReadType(SourceString);
			if(!type) {
				if(SourceString.IsEmpty()) {
					SourceString = ".....";
				}
				SourceString++;
				_getch();
				return 0;
			}
		} else if(Instruction == 0xD0 || Instruction == 0xD1)ReadMemoryText(Instruction, SourceString);
		if(source_reader.EndOfText()) {
			printf("∂¡»°Ω· ¯°£");
			_getch();
			return 0;
		}
	}

	return 0;
}