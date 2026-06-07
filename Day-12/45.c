//Write a program to Write function for palindrome.
#include <stdio.h>
int isPal(int n);
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    isPal(n);
    return 0;
}
int isPal(int n){
    int temp=n;
    int rev=0,r;
    while(n!=0){
        r=n%10;
        rev=rev*10+r;
        n=n/10;
    }
    if (temp==rev){
        printf("%d is a pallindrome",temp);
    } else {
        printf("Not a pallindrome");
    }
}