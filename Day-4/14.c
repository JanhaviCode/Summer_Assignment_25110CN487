// Write a program to find nth fibonacci term.
#include <stdio.h>
int main (){
    int n,a=0,b=1,fib,i;
    printf ("Enter the number=");
    scanf("%d",&n);
    for(i=3;i<=n;i++)
    {
        fib=a+b;
        a=b;
        b=fib;
    }
    if(n==1) {
    printf("%d",a);}
    else {
     printf("%d",b);}
    return 0;
}
    
