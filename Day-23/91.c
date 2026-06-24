#include <stdio.h>
#include <string.h>
int main(){
    char str1[100],str2[100];
    int n1,n2;

    printf("Enter first string: ");
    scanf("%s", str1);
    n1=strlen(str1);

printf("Enter second string: ");
scanf("%s", str2);
n2=strlen(str2);
    if(n1 != n2){
        printf("The strings are not anagrams.\n");
    } else {
        int same=0;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (str1[i] == str2[j]) {
                    str2[j] = '-'; 
                    same ++;
                    break;
                }
            }
        }
        if (same == n1) {
            printf("The strings are anagrams.\n");
        } else {
            printf("The strings are not anagrams.\n");
        }
    }
}