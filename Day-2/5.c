// write a program to find sum of digits of a number.
#include <stdio.h>
int main (){
    int n,sum=0,r;
    printf ("Enter the number=");
    scanf("%d",&n);
    while(n>0){
        r=n%10;
        sum+=r;
        n=n/10;
    }
    printf("The sum of the digits is=%d",sum);
}