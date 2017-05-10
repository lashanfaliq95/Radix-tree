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
   int i;
    /*   printf("inserting \n" );
      for(i=0;i<NUMBER_OF_WORDS;i++){
      	insert(root,words[i]);
      }
      printf("insered \n" );*/
      printf("hel \n");
      insert(root,"abcd");
      insert(root,"abcdef");
      insert(root,"abcdgg");
      insert(root,"bbc");
      insert(root,"bbcd");
       insert(root,"bbcg")
      insert(root,"compute");
      insert(root,"computer");
      insert(root,"computed");
       insert(root,"computgd");
      trieToRadix(root);
      printf("%s\n",root->children[0]->label );
      printf("%s\n",root->children[1]->label );
      printf("%s\n",root->children[2]->label );
      printf("end" );
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
