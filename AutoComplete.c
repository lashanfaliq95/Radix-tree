#include "AutoCompleteImpl.h"

#define NUMBER_OF_WORDS (354935)
#define INPUT_WORD_SIZE (100)
static char* words[NUMBER_OF_WORDS];
static struct  TrieNode *root;

char *receiveInput(char *s) {
	scanf("%99s", s);
	return s;
}

int main(){
	int word_count = 0;


	FILE *fp = fopen("dictionary.txt", "r");
	if (fp == 0){
		perror("error");
		fprintf(stderr, "Error while opening dictionary file");
		exit(1);
	}

	words[word_count] = malloc(INPUT_WORD_SIZE);
   fgets( words[word_count], INPUT_WORD_SIZE,(FILE*) fp);//to flush the buffer or u get a error


   while (fgets( words[word_count], INPUT_WORD_SIZE,(FILE*) fp)) {

   	word_count++;
   	words[word_count] = malloc(INPUT_WORD_SIZE);
   } 
   
   root=createTrieNode();
      insert(root,"abcd");
      insert(root,"abcded");
      insert(root,"abcfk");
      insert(root,"compute");
      insert(root,"computer");
 printf("%s\n",root->children[0]->label);
 printf("%s\n",root->children[2]->label);
    trieToRadix(root);
 printf("%s\n",root->children[0]->label);
 printf("%s\n",root->children[0]->children[3]->label);
 printf("%s\n",root->children[2]->label);
//	printf("%s\n",root->children[2]->children[17]->label);
      while(1){

        printf("Enter keyword: ");
         char str[100];
        receiveInput(str);
                TrieNode * node = search1(root,str);
                printf("%s\n",node->label );
        traverseRadix(str,node);

      }
     /*while (1) {

        printf("Enter keyword: ");
        char str[100];
        receiveInput(str);
        printf("\n==========================================================\n");
        printf("\n********************* Possible Words ********************\n");
        TrieNode * node = search(root,str);
        traverseRadix(str,node);
        printf("==========================================================\n");
    }*/
    }
