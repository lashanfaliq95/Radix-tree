#include "AutoCompleteImpl.h"
char* stradd(const char* a, const int b){
  size_t len = strlen(a);
    char *str2 =(char*)malloc(len * sizeof(char) + 2); /* one for extra char, one for trailing zero */
  strcpy(str2, a);
  str2[len] = b+'a';
  str2[len+1]='\0';
  return str2;
}

struct TrieNode *createTrieNode() {
  struct TrieNode *temp;
  temp=(struct TrieNode *)malloc(sizeof(struct TrieNode));
  int i;
    for( i=0;i<26;i++){//making all the children
      temp->children[i]=NULL;
    }
    temp->isEndOfWord=false;
   return temp;
}

void insert(struct TrieNode *root, const char *word) {

  int size=strlen(word);

  struct TrieNode *currentNode=root;
  int index;
  int i;
  for( i=0;i<size-1;i++){
    index=CHAR_TO_INDEX(word[i]);
    
      if(currentNode->children[index]==NULL){//when first creating the child
        currentNode->children[index]=createTrieNode();
        currentNode=currentNode->children[index];

      }
      else{//when a child is already there
        currentNode=currentNode->children[index];

      }
  }
  currentNode->isEndOfWord=true;
 
}

struct TrieNode *search(struct TrieNode *root, const char *word) {
    int size=strlen(word);
  int index,i;
  struct TrieNode *currentNode=root;
  for(i=0;i<size;i++){
    index=CHAR_TO_INDEX(word[i]);
    currentNode=currentNode->children[index];
  }
  return currentNode;
}
void traverse(char prefix[], struct TrieNode *root){
if(root==NULL){//if word enterd is wrong
  printf("Enter correct word\n");
}
else{
  int i=0;
  if(root->isEndOfWord==true){
    printf("%s\n",prefix);
  }
  while(i<26){
    if(root->children[i]!=NULL){
      traverse(stradd(prefix,i),root->children[i]);//calling traverse again for the new prefix
    }
    i++;
  }
}
}