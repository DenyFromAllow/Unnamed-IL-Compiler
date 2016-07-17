#pragma once

class SIMPLE_TRIETREE {
protected:
	class TrieNode {
	public:
		uint32 String;
		TrieNode* Child[256];
		TrieNode() {
			//printf("bbb");
			for(uint16 i = 0; i < 256; i++)Child[i] = nullptr;
			String = 0;
		}
	};
	TrieNode root;
public:
	/*
	SIMPLE_TRIETREE() :root() {
		printf("aaa");
		root = TrieNode();
	}*/
	void add(const char*str,uint32 num) {
		TrieNode* node = &root;
		for(; *str != 0; str++) {
			if(!node->Child[(uint8)*str]) {
				node->Child[(uint8) *str] = new TrieNode;
				node = node->Child[(uint8) *str];
			} else {
				node = node->Child[(uint8) *str];
			}
		}
		if(!node->String)node->String = num;
	}
	uint32 find(const char*str) {
		TrieNode* node = &root;
		for(; *str != 0; str++) {
			if(!node->Child[(uint8) *str]) {
				return 0;
			} else {
				node = node->Child[(uint8) *str];
			}
		}
		return node->String;
	}

};