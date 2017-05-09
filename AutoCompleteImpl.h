#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct TrieNode{
	struct TrieNode *children[ALPHABET_SIZE];
	char * label;
	bool isEndOfWord;

} TrieNode;


struct TrieNode *createTrieNode();
struct TrieNode *search(struct TrieNode *root, const char *word);
void traverse(char prefix[], struct TrieNode *root);
void insert(struct TrieNode *root, const char *word);
char* stradd(const char* a, const int b);
char* stradd1(const char* a,const char* b);
void traverseRadix(char prefix[], struct TrieNode *root);
void trieToRadix(struct TrieNode *root);
