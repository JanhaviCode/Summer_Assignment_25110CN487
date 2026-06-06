//Write a program to Write function to find factorial.
#include <stdio.h>
int factorial(int n);
int main(){
    int n;
    printf("Enter the number to find the factorial for:");
    scanf("%d",&n);
    printf("factorial of %d = %d",n,factorial(n));
    return 0;
}
int factorial(int n){
    int product=1;
    for (int i=1;i<=n;i++){
        product*=i;
    }
    return product;
}