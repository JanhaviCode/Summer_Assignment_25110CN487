#include <stdio.h>
#include <string.h>
int main(){
    char str[100],comp[100];
    int n1,j=0;
    printf("Enter first string: ");
    scanf("%s", str);
    strlwr(str);
    n1=strlen(str);
    for(int i=0;i<n1;i++){
        int count=1;
        for(int j=i+1;j<n1;j++){
            if(str[i]==str[j] && str[i]!='-'){
                count++;
                str[j]='-';
            }
        }
        if(str[i]!='-'){
            comp[j++]=str[i];
            comp[j++]=count+'0';
        }
    }
    comp[j]='\0';
    printf("Compressed string: %s\n", comp);
}