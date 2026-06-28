// Write a program to Create menu-driven array operations system.
#include <stdio.h>

void display(int arr[], int n);
void sum(int arr[], int n);
void largest(int arr[], int n);
void search(int arr[], int n);

int main() {
    int arr[100], n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n===== ARRAY MENU =====\n");
        printf("1. Display Array\n");
        printf("2. Find Sum\n");
        printf("3. Find Largest Element\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display(arr, n);
                break;

            case 2:
                sum(arr, n);
                break;

            case 3:
                largest(arr, n);
                break;

            case 4:
                search(arr, n);
                break;

            case 5:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}

// Function to display array
void display(int arr[], int n) {
    printf("Array Elements: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to find sum
void sum(int arr[], int n) {
    int s = 0;

    for(int i = 0; i < n; i++)
        s += arr[i];

    printf("Sum = %d\n", s);
}

// Function to find largest element
void largest(int arr[], int n) {
    int max = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    printf("Largest Element = %d\n", max);
}

// Function to search an element
void search(int arr[], int n) {
    int key, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Element not found.\n");
}