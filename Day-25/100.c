#include <stdio.h>
#include <string.h>

int main() {
    char word[5][20],temp[20];
    int len1,len2;

    printf("Enter 5 words:\n");

    for(int i=0;i<5;i++)
        scanf("%s",word[i]);

    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){

            len1=strlen(word[i]);
            len2=strlen(word[j]);

            if(len1>len2){
                strcpy(temp,word[i]);
                strcpy(word[i],word[j]);
                strcpy(word[j],temp);
            }
        }
    }

    printf("Words sorted by length:\n");

    for(int i=0;i<5;i++)
        printf("%s\n",word[i]);
}