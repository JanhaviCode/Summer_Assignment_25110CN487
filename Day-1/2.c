// Write a program to print multiplication table of of a number.
#include <stdio.h>
int main(){
    int i,n ;
    printf("Enter a number=");
    scanf("%d",&n);
    for(i=1; i<=10; i++){
        printf("%d x %d = %d \n",n,i,n*i);
    }

}