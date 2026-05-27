// Write a program to count the digits of a number
#include <stdio.h>
int main (){
    int n , len=0;
    printf("Enter the number=");
    scanf("%d",&n);
    while(n>0){
        n=n/10;
        len++;
    }
    printf("The number of digits %d",len);
}