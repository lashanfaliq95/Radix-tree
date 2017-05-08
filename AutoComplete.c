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
         for(i=0;i<NUMBER_OF_WORDS;i++){
        insert(root,words[i]);
    }
    while (1) {
        printf("Enter keyword: ");
        char str[100];
        receiveInput(str);
        printf("\n==========================================================\n");
        printf("\n********************* Possible Words ********************\n");
        TrieNode * node = search(root,str);
        traverse(str,node);
        printf("==========================================================\n");
    }
}
