//Write a program to Check strong number.
#include <stdio.h>
int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
int main(){
    int n,temp,sum=0,r;
    printf("Enter a number: ");
    scanf("%d",&n);
    temp=n;
    while(temp!=0){
        r=temp%10;
        sum+=factorial(r);
        temp=temp/10;
    }
    if(sum==n){
        printf("%d is a Strong number",n);
    } else {
        printf("%d is not a Strong number",n);
    }
    return 0;
}
