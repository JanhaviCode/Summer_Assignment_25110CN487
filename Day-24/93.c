//Write a program to Check string rotation.
#include <stdio.h>
#include <string.h>
int main(){
    char str1[100],str2[100];
    int n1,n2;
    printf("Enter first string: ");
    scanf("%s", str1);
    strupr(str1);
    n1=strlen(str1);

    printf("Enter second string: ");
    scanf("%s", str2);
    strupr(str2);
    n2=strlen(str2);
    if(n1 != n2){
        printf("The strings are not rotations of each other.\n");
    } else {
        for (int i = 0; i < n1; i++) {
            char temp = str1[0];
            for (int j = 0; j < n1 - 1; j++) {
                str1[j] = str1[j + 1];
            }
            str1[n1 - 1] = temp;
            if (strcmp(str1, str2) == 0) {
                printf("The strings are rotations of each other.\n");
                return 0;
            }
        }
        printf("The strings are not rotations of each other.\n");
    }
}