#include"Simple\simple.h"
using namespace Simple;

int main() {
	String HelloWorld;
	HelloWorld << 'H';
	HelloWorld << 'e';
	HelloWorld << 'l';
	HelloWorld << 'l';
	HelloWorld << 'o';
	HelloWorld << ',';
	HelloWorld << 'W';
	HelloWorld << 'o';
	HelloWorld << 'r';
	HelloWorld << 'l';
	HelloWorld << 'd';
	HelloWorld << '!';
	HelloWorld++;
	Sleep(5_sec);
	return 0;
}