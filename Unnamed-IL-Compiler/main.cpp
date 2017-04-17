#include <iostream>
#include <fstream>
#include <vector>
#include "main.h"
using namespace std;

SIMPLE_TRIETREE MainDict;
SIMPLE_TRIETREE TypeDict;
SIMPLE_TRIETREE FunctionDict;
ofstream OutFile;
SIMPLE_TEXTREADER *SourceReader;
Block *currentBlock = nullptr;
String SourceString;

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
	String LowerSourceString;
	for(;;) {
		check();
		source_reader.ReadWord(SourceString);
		if(SourceString) {
			LowerSourceString = SourceString;
			LowerSourceString.ToLowerCase();
			if(uint32 Instruction = MainDict.findPrefix(LowerSourceString.begin())) {
				if(Instruction > 0x0 && Instruction < 0xc0) {

				} else if(Instruction >= 0xD0 && Instruction <= 0xFF) {
					ReadDirective(Instruction);
				}
			} else if(uint32 type = ReadType(SourceString)) {

			}
		}
		if(source_reader.EndOfText()) {
			printf("¶ÁÈ¡½áÊø¡£");
			_getch();
			return 0;
		}
	}

	return 0;
}