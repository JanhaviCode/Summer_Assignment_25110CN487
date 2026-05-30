// WAP to print the armstrong number in a range.
#include <stdio.h>
#include <math.h>
int main()
{
    int start, end, num, temp, rem, sum, digits;
    printf("Enter start and end: ");
    scanf("%d %d", &start, &end);
    for(num = start; num <= end; num++)
    {
        temp = num;
        digits = 0;
        // Count number of digits
        while(temp != 0)
        {
            digits++;
            temp = temp / 10;
        }
        
        temp = num;
        sum = 0;
        // Calculate sum of digits raised to power of digit count
        while(temp != 0)
        {
            rem = temp % 10;
            sum = sum + pow(rem, digits);
            temp = temp / 10;
        }
        if(sum == num)
            printf("%d ", num);
    }
    return 0;
}