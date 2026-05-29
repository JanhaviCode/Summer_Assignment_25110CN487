// Write a program to check weather a number is prime .
#include <stdio.h>
int main (){
    int n , i, flag=1;
    printf("Enter a number");
    scanf("%d",&n);
    if (n<=1){
        flag=0;
    }
    for(i=2; i<=n/2; i++){
        if (n%i==0){
            flag=0;
            break;
        }
    }
    if (flag==1)
    printf("%d is a Prime number",n);
    else
    printf("%d is not a Prime number",n);
}  