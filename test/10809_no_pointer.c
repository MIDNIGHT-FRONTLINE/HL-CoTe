#include <stdio.h>
#include <string.h>

int main(){
    char word[100];
    int alp[26];
    int n;

    scanf("%s", word);
  
    for(int i=0; i<26; i++){
        alp[i] = -1;
    }

    for(int i=0; i<strlen(word); i++){
        n = word[i]-'a';

        if(alp[n]==-1){
            alp[n]=i;
        }
    }

    for(int i=0; i<26; i++){
        printf("%d ",alp[i]);
    }
    return 0;
}