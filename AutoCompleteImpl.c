#include "AutoCompleteImpl.h"
char* stradd(const char* a, const int b){
  size_t len = strlen(a);
    char *str2 =(char*)malloc(len * sizeof(char) + 2); /* one for extra char, one for trailing zero */
  strcpy(str2, a);
  str2[len] = b+'a';
  str2[len+1]='\0';
  return str2;
}
char* stradd1(const char* a,const char* b){
  size_t len = strlen(a)+strlen(b);
    char *str2 =(char*)malloc(len * sizeof(char) + 2); /* one for extra char, one for trailing zero */
  strcpy(str2, a);
  strcat(str2,b);
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
    temp->label=NULL;
    return temp;
  }

  void insert(struct TrieNode *root, const char *word) {

    int size=strlen(word);
   
    struct TrieNode *currentNode=root;
    int index,i;
    for( i=0;i<size-1;i++){
      index=CHAR_TO_INDEX(word[i]);
      
      if(currentNode->children[index]==NULL){//when first creating the child
        currentNode->children[index]=createTrieNode();
        currentNode=currentNode->children[index];
        currentNode->label=(char*)malloc(sizeof(char)+2);//creating the label
        currentNode->label[0]=word[i];
        currentNode->label[1]='\0';
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
   struct TrieNode *search1(struct TrieNode *root, const char *word) {
    struct TrieNode *currentNode=root;
    int j,i=0,index=0,temp,size=strlen(word);
  
    bool equal;
    while(index<size){
        if(currentNode->children[i]!=NULL){
         int len=strlen(currentNode->children[i]->label);
           
            if(word[index]==currentNode->children[i]->label[0]){
                
                currentNode=currentNode->children[i];
                i=0;
                  for(j=0;j<len;j++){
            index++;
         }
               }
      
        
      }
       i++;
      
    }
    return currentNode;
  }

void trieToRadix(struct TrieNode *root){//compressing the tree
  struct TrieNode *temp=root;
  int i,count=0,len,index=0,j=0;
  bool cond=false;
  for(i=0;i<26;i++){
    if(root->children[i]!=NULL){
      count++;//to check if the node has only one child
      index=i;
    }
  } 

  if(count==1 && root->label!=NULL){//to bypass the root we use the second condition
    struct TrieNode *temp=root->children[index];
    len=strlen(root->label);//len of the word in current node
    
  //reallocating mem for the new word
    root->label=stradd(root->label,index);//getiing the new word combining with the cahracter in the next word
   
     for(i=0;i<26;i++){//freeing the children of the current node
      if(root->children[i]!=NULL){//if the next node has a  child
      root->children[i]=NULL;
      free(root->children[i]);
      }
    }

    for(i=0;i<26;i++){
      if(temp->children[i]!=NULL){//if the next node has a  child
        if (root->children[i]==NULL){//if the current node doesnt have a node in that slot
          root->children[i]=createTrieNode();
         }
        root->children[i]=temp->children[i];//if it already has node in that slot
        if(temp->isEndOfWord==true)
         root->isEndOfWord=true;
      }
    }
     if(temp->isEndOfWord==true)
         root->isEndOfWord=true;
    free(temp);
    cond=true;
     } 
 bool condition=true;

  for (i = 0; i <26; ++i)
  {
    if(root->children[i]!=NULL){
      condition=false;
     }
  }
  if(condition==true)
    return;

  while(j<26){
    if(root->children[j]!=NULL){
      if(cond==true){
         trieToRadix(root);
      }
      else{
      trieToRadix(root->children[j]);}
    }
    j++;
  }
}
  void traverseRadix(char prefix[], struct TrieNode *root){

if(root==NULL){//if word enterd is wrong
  printf("Enter correct word\n");
}
else{
  int i=0;
  if(root->isEndOfWord==true ){
    printf("%s\n",prefix);

    
  }
  while(i<26){
    if(root->children[i]!=NULL){
      traverseRadix(stradd1(prefix,root->children[i]->label),root->children[i]);//calling traverse again for the new prefix
    }
    i++;
  }
}
}
