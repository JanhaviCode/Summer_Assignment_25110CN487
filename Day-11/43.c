// Write a program to Write function to check prime
#include <stdio.h>
#include <stdbool.h>
bool check_prime(int n);
int main(){
    int n;
    bool check;
    printf("Enter the number to check prime:");
    scanf("%d",&n);
    check=check_prime(n);
    if(check==1){
        printf("%d is a prime number",n);
    } else {
        printf("%d is not a prime number",n);
    }
    return 0;
}
bool check_prime(int n){
    int flag=0;
    for (int i=1;i<=n;i++){
        if(n%i==0){
            flag++;
        }
    }
    if (flag==2){
        return 1;
    } else {
        return 0;
    }
}