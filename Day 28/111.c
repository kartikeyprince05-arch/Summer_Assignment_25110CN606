#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50
#define NAME_LEN 50

// Structure to store booking details
typedef struct {
    int seatNumber;
    char name[NAME_LEN];
    int isBooked;
} Ticket;

Ticket tickets[MAX_SEATS];

// Initialize tickets
void initTickets() {
    for (int i = 0; i < MAX_SEATS; i++) {
        tickets[i].seatNumber = i + 1;
        tickets[i].isBooked = 0;
        strcpy(tickets[i].name, "");
    }
}

// Display available seats
void viewAvailableTickets() {
    printf("\nAvailable Seats:\n");
    int availableCount = 0;
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!tickets[i].isBooked) {
            printf("%d ", tickets[i].seatNumber);
            availableCount++;
        }
    }
    if (availableCount == 0) {
        printf("No seats available.");
    }
    printf("\n");
}

// Book a ticket
void bookTicket() {
    int seat;
    char name[NAME_LEN];

    viewAvailableTickets();
    printf("\nEnter seat number to book: ");
    if (scanf("%d", &seat) != 1 || seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number.\n");
        while (getchar() != '\n'); // clear input buffer
        return;
    }

    if (tickets[seat - 1].isBooked) {
        printf("Seat %d is already booked.\n", seat);
        return;
    }

    printf("Enter your name: ");
    while (getchar() != '\n'); // clear buffer
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline

    tickets[seat - 1].isBooked = 1;
    strcpy(tickets[seat - 1].name, name);

    printf("✅ Ticket booked successfully for %s (Seat %d)\n", name, seat);
}

// Cancel a ticket
void cancelTicket() {
    int seat;
    printf("\nEnter seat number to cancel: ");
    if (scanf("%d", &seat) != 1 || seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number.\n");
        while (getchar() != '\n');
        return;
    }

    if (!tickets[seat - 1].isBooked) {
        printf("Seat %d is not booked.\n", seat);
        return;
    }

    printf("Booking for %s (Seat %d) canceled.\n", tickets[seat - 1].name, seat);
    tickets[seat - 1].isBooked = 0;
    strcpy(tickets[seat - 1].name, "");
}

// Display all bookings
void viewBookings() {
    printf("\nCurrent Bookings:\n");
    int bookedCount = 0;
    for (int i = 0; i < MAX_SEATS; i++) {
        if (tickets[i].isBooked) {
            printf("Seat %d - %s\n", tickets[i].seatNumber, tickets[i].name);
            bookedCount++;
        }
    }
    if (bookedCount == 0) {
        printf("No bookings yet.\n");
    }
}

int main() {
    int choice;
    initTickets();

    while (1) {
        printf("\n===== Ticket Booking System =====\n");
        printf("1. View Available Tickets\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. View All Bookings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: viewAvailableTickets(); break;
            case 2: bookTicket(); break;
            case 3: cancelTicket(); break;
            case 4: viewBookings(); break;
            case 5: printf("Exiting... Thank you!\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
