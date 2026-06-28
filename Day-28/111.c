#include <stdio.h>
#include <stdlib.h>

struct Ticket {
    int ticketNo;
    char name[50];
    char destination[50];
    int seats;
};

void bookTicket() {
    struct Ticket t;
    FILE *fp = fopen("ticket.txt", "a");

    printf("Enter Ticket Number: ");
    scanf("%d", &t.ticketNo);

    printf("Enter Passenger Name: ");
    scanf("%s", t.name);

    printf("Enter Destination: ");
    scanf("%s", t.destination);

    printf("Enter Number of Seats: ");
    scanf("%d", &t.seats);

    fprintf(fp, "%d %s %s %d\n", t.ticketNo, t.name, t.destination, t.seats);

    fclose(fp);
    printf("Ticket Booked Successfully.\n");
}

void displayTickets() {
    struct Ticket t;
    FILE *fp = fopen("ticket.txt", "r");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("\nTicketNo\tName\tDestination\tSeats\n");

    while (fscanf(fp, "%d %s %s %d", &t.ticketNo, t.name, t.destination, &t.seats) != EOF) {
        printf("%d\t\t%s\t%s\t\t%d\n", t.ticketNo, t.name, t.destination, t.seats);
    }

    fclose(fp);
}

void searchTicket() {
    struct Ticket t;
    int num, found = 0;

    FILE *fp = fopen("ticket.txt", "r");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Ticket Number: ");
    scanf("%d", &num);

    while (fscanf(fp, "%d %s %s %d", &t.ticketNo, t.name, t.destination, &t.seats) != EOF) {
        if (t.ticketNo == num) {
            printf("\nTicket Found\n");
            printf("Ticket No: %d\n", t.ticketNo);
            printf("Passenger: %s\n", t.name);
            printf("Destination: %s\n", t.destination);
            printf("Seats: %d\n", t.seats);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Ticket Not Found.\n");
}

void updateTicket() {
    struct Ticket t;
    int num, found = 0;

    FILE *fp = fopen("ticket.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Ticket Number to Update: ");
    scanf("%d", &num);

    while (fscanf(fp, "%d %s %s %d", &t.ticketNo, t.name, t.destination, &t.seats) != EOF) {
        if (t.ticketNo == num) {
            printf("Enter New Passenger Name: ");
            scanf("%s", t.name);

            printf("Enter New Destination: ");
            scanf("%s", t.destination);

            printf("Enter New Number of Seats: ");
            scanf("%d", &t.seats);

            found = 1;
        }

        fprintf(temp, "%d %s %s %d\n", t.ticketNo, t.name, t.destination, t.seats);
    }

    fclose(fp);
    fclose(temp);

    remove("ticket.txt");
    rename("temp.txt", "ticket.txt");

    if (found)
        printf("Ticket Updated Successfully.\n");
    else
        printf("Ticket Not Found.\n");
}

void cancelTicket() {
    struct Ticket t;
    int num, found = 0;

    FILE *fp = fopen("ticket.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Ticket Number to Cancel: ");
    scanf("%d", &num);

    while (fscanf(fp, "%d %s %s %d", &t.ticketNo, t.name, t.destination, &t.seats) != EOF) {
        if (t.ticketNo == num) {
            found = 1;
            continue;
        }

        fprintf(temp, "%d %s %s %d\n", t.ticketNo, t.name, t.destination, t.seats);
    }

    fclose(fp);
    fclose(temp);

    remove("ticket.txt");
    rename("temp.txt", "ticket.txt");

    if (found)
        printf("Ticket Cancelled Successfully.\n");
    else
        printf("Ticket Not Found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Ticket Booking System =====\n");
        printf("1. Book Ticket\n");
        printf("2. Display Tickets\n");
        printf("3. Search Ticket\n");
        printf("4. Update Ticket\n");
        printf("5. Cancel Ticket\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                displayTickets();
                break;
            case 3:
                searchTicket();
                break;
            case 4:
                updateTicket();
                break;
            case 5:
                cancelTicket();
                break;
            case 6:
                printf("Thank You!\n");
                return 0;
            default:
                printf("Invalid Choice.\n");
        }
    }
}