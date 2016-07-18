#include <iostream>
#include <fstream>
#include "main.h"
using namespace Simple;
using namespace std;

SIMPLE_TRIETREE MainTrie;
ofstream OutFile;
SIMPLE_TEXTREADER SourceReader;

int main() {
	InitInstructions();
	InitReader();

	return 0;
}