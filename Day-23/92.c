#include <stdio.h>
#include <string.h>
int main(){
    char str1[100];
    int n1;
    char rep;
    int max=0;
    printf("Enter first string: ");
    scanf("%s", str1);
    n1=strlen(str1);
    for (int i=0; i<n1;i++){
        int count=1;
        for (int j=i+1;j<n1;j++){
            if (str1[i]==str1[j] && str1[i]!='-' ){
                count++;
            }
            if(count>max){
                max=count;
                rep=str1[i];
            }
        }
    }
    printf("The most repeated character in the string is: %c\n", rep);
}