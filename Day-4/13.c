// write a program to generate the fibonacci series
#include <stdio.h>
int main (){
    int n, i, a=0, b=1, fib;
    printf("Enter the number=");
    scanf("%d",&n);
     for(i=1; i<= n; i++){
        printf("%d ", a);
       fib = a + b;
        a = b;
        b = fib;
    }

}