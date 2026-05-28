// write a program to find the product of a digit
#include <stdio.h>
int main (){
    int n,product=1,r;
    printf ("Enter the number=");
    scanf("%d",&n);
    while(n>0){
        r=n%10;
        product*=r;
        n=n/10;
    }
    printf("The product of the digits is=%d",product);
}