// Write the program to check armstrong number.
#include <stdio.h>

int main(){
 int n, temp, r, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    n=temp;
    while (temp != 0){
        r = temp % 10;
        sum = sum + r*r*r;
        n = n/ 10;
    }
    if (sum == temp)
        printf("Armstrong Number");
    else
        printf("Not an Armstrong Number");
    return 0;
}