#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float m1, m2, m3, m4, m5;
    float total, percentage;
    char grade;
};

void generateMarksheet() {
    struct Student s;

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks of 5 Subjects:\n");
    scanf("%f%f%f%f%f", &s.m1, &s.m2, &s.m3, &s.m4, &s.m5);

    s.total = s.m1 + s.m2 + s.m3 + s.m4 + s.m5;
    s.percentage = s.total / 5;

    if (s.percentage >= 90)
        s.grade = 'A';
    else if (s.percentage >= 75)
        s.grade = 'B';
    else if (s.percentage >= 60)
        s.grade = 'C';
    else if (s.percentage >= 40)
        s.grade = 'D';
    else
        s.grade = 'F';

    printf("\n========== MARKSHEET ==========\n");
    printf("Roll Number : %d\n", s.roll);
    printf("Name        : %s\n", s.name);

    printf("\nSubject\tMarks\n");
    printf("Sub1\t%.2f\n", s.m1);
    printf("Sub2\t%.2f\n", s.m2);
    printf("Sub3\t%.2f\n", s.m3);
    printf("Sub4\t%.2f\n", s.m4);
    printf("Sub5\t%.2f\n", s.m5);

    printf("-------------------------------\n");
    printf("Total       : %.2f\n", s.total);
    printf("Percentage  : %.2f%%\n", s.percentage);
    printf("Grade       : %c\n", s.grade);

    if (s.grade == 'F')
        printf("Result      : Fail\n");
    else
        printf("Result      : Pass\n");
}

int main() {
    generateMarksheet();
    return 0;
}