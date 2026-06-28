#include <stdio.h>
#include <string.h>

int movieId[100], seats[100], price[100], n = 0, bookingId = 1000;
char movieName[100][50], theatre[100][50], showTime[100][30];

void addMovie();
void displayMovies();
void searchMovie();
void updateMovie();
void deleteMovie();
void adminMenu();
void customerMenu();
void bookTicket();
void cancelTicket();
void checkSeats();

int main() {
    int ch;

    do {
        printf("\n====== BOOK MY MOVIE SYSTEM ======\n");
        printf("1. Admin\n2. Customer\n3. Exit\nChoice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                adminMenu();
                break;
            case 2:
                customerMenu();
                break;
            case 3:
                printf("Thank You!\n");
                break;
            default:
                printf("Invalid Choice\n");
        }

    } while(ch != 3);

    return 0;
}

void adminMenu() {
    int ch;

    do {
        printf("\n--- ADMIN MENU ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Update Movie\n");
        printf("5. Delete Movie\n");
        printf("6. Back\n");
        printf("Choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: addMovie(); break;
            case 2: displayMovies(); break;
            case 3: searchMovie(); break;
            case 4: updateMovie(); break;
            case 5: deleteMovie(); break;
        }

    } while(ch!=6);
}

void customerMenu() {
    int ch;

    do {
        printf("\n--- CUSTOMER MENU ---\n");
        printf("1. View Movies\n");
        printf("2. Search Movie\n");
        printf("3. Book Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Check Seats\n");
        printf("6. Back\n");
        printf("Choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: displayMovies(); break;
            case 2: searchMovie(); break;
            case 3: bookTicket(); break;
            case 4: cancelTicket(); break;
            case 5: checkSeats(); break;
        }

    } while(ch!=6);
}

void addMovie() {

    printf("Movie ID: ");
    scanf("%d",&movieId[n]);

    printf("Movie Name: ");
    scanf(" %[^\n]",movieName[n]);

    printf("Theatre: ");
    scanf(" %[^\n]",theatre[n]);

    printf("Show Time: ");
    scanf(" %[^\n]",showTime[n]);

    printf("Available Seats: ");
    scanf("%d",&seats[n]);

    printf("Ticket Price: ");
    scanf("%d",&price[n]);

    n++;
}

void displayMovies() {

    int i;

    if(n==0) {
        printf("No Movies Available\n");
        return;
    }

    for(i=0;i<n;i++) {

        printf("\nMovie ID : %d",movieId[i]);
        printf("\nMovie    : %s",movieName[i]);
        printf("\nTheatre  : %s",theatre[i]);
        printf("\nShow Time: %s",showTime[i]);
        printf("\nSeats    : %d",seats[i]);
        printf("\nPrice    : %d\n",price[i]);
    }

}

void searchMovie() {

    int id,i,f=0;

    printf("Enter Movie ID: ");
    scanf("%d",&id);

    for(i=0;i<n;i++) {

        if(movieId[i]==id) {

            printf("\nMovie : %s",movieName[i]);
            printf("\nTheatre : %s",theatre[i]);
            printf("\nShow Time : %s",showTime[i]);
            printf("\nSeats : %d",seats[i]);
            printf("\nPrice : %d\n",price[i]);

            f=1;
        }
    }

    if(f==0)
        printf("Movie Not Found\n");

}

void updateMovie() {

    int id,i;

    printf("Enter Movie ID: ");
    scanf("%d",&id);

    for(i=0;i<n;i++) {

        if(movieId[i]==id) {

            printf("New Movie Name: ");
            scanf(" %[^\n]",movieName[i]);

            printf("New Theatre: ");
            scanf(" %[^\n]",theatre[i]);

            printf("New Show Time: ");
            scanf(" %[^\n]",showTime[i]);

            printf("New Seats: ");
            scanf("%d",&seats[i]);

            printf("New Ticket Price: ");
            scanf("%d",&price[i]);

            return;
        }
    }

    printf("Movie Not Found\n");

}

void deleteMovie() {

    int id,i,j;

    printf("Enter Movie ID: ");
    scanf("%d",&id);

    for(i=0;i<n;i++) {

        if(movieId[i]==id) {

            for(j=i;j<n-1;j++) {

                movieId[j]=movieId[j+1];
                seats[j]=seats[j+1];
                price[j]=price[j+1];

                strcpy(movieName[j],movieName[j+1]);
                strcpy(theatre[j],theatre[j+1]);
                strcpy(showTime[j],showTime[j+1]);

            }

            n--;

            printf("Movie Deleted Successfully\n");
            return;
        }
    }

    printf("Movie Not Found\n");

}

void bookTicket() {

    int id,i,tickets;
    char name[50];

    printf("Enter Movie ID: ");
    scanf("%d",&id);

    for(i=0;i<n;i++) {

        if(movieId[i]==id) {

            printf("Customer Name: ");
            scanf(" %[^\n]",name);

            printf("Number of Tickets: ");
            scanf("%d",&tickets);

            if(tickets>seats[i]) {

                printf("Seats Not Available\n");
                return;
            }

            seats[i]-=tickets;

            printf("\n========== MOVIE TICKET ==========\n");
            printf("Booking ID : %d\n",bookingId++);
            printf("Customer   : %s\n",name);
            printf("Movie      : %s\n",movieName[i]);
            printf("Theatre    : %s\n",theatre[i]);
            printf("Show Time  : %s\n",showTime[i]);
            printf("Tickets    : %d\n",tickets);
            printf("Total Bill : %d\n",tickets*price[i]);
            printf("Status     : Confirmed\n");
            printf("==================================\n");

            return;
        }
    }

    printf("Movie Not Found\n");

}

void cancelTicket() {

    int id,i,tickets;

    printf("Enter Movie ID: ");
    scanf("%d",&id);

    for(i=0;i<n;i++) {

        if(movieId[i]==id) {

            printf("Tickets to Cancel: ");
            scanf("%d",&tickets);

            seats[i]+=tickets;

            printf("Cancellation Successful\n");
            return;
        }
    }

    printf("Movie Not Found\n");

}

void checkSeats() {

    int id,i;

    printf("Enter Movie ID: ");
    scanf("%d",&id);

    for(i=0;i<n;i++) {

        if(movieId[i]==id) {

            printf("Available Seats: %d\n",seats[i]);
            return;
        }
    }

    printf("Movie Not Found\n");

}