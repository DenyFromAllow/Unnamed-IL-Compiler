#include <iostream>
#include"Simple\simple.h"
using namespace Simple;
using namespace std;

int main() {
	SIMPLE_TRIETREE trie;
	trie.add("asd", 1);
	trie.add("dsa", 2);
	trie.add("c++", 3);
	trie.add("整数", 4);

	cout << trie.find("c++");
	cout << trie.find("整数");
	trie.PrintAll();

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