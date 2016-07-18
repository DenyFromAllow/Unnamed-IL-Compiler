#pragma once

class SIMPLE_TRIETREE {
protected:
	class TrieNode {
	public:
		TrieNode* Child[4] = { nullptr,nullptr,nullptr,nullptr };
		uint32 String = 0;

	};
	TrieNode root;
	void Print(TrieNode* node, SIMPLE_STRING str, uint8 bitidx, char otptchar, uint8 idx);
public:
	void add(const char*str, uint32 num);
	uint32 find(const char*str);
	void PrintAll();

};