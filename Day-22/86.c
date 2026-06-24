//Write a program to Count words in a sentence
#include <stdio.h>
#include <string.h>
int main() {
    char sentence[100];
    int count = 0;
    int i;
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    for (i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ') {
            count++;
        }
    }
    count++;
    printf("Number of words in the sentence = %d\n", count);
    return 0;
}