/*
* Bus Ticket Booking System
* Simple terminal program for booking bus tickets written in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// predefining Basic limits don't go rogue on the values lol
#define MAX_SEATS 40
#define MAX_PASSENGERS 5
#define MAX_ROUTES 10

// passenger info
struct passenger {
    char name[50];           // passenger name
    char address[100];       // where they live
    int age;                 // how old they are
    char blood_group[5];     // blood type for emergencies
    char phone[15];          // phone number
    char email[50];          // email address
    char gender;             // M or F
};

// Route info - costs and stuffs
struct route {
    int id;                  // route number
    char from[30];           // starting city
    char to[30];             // destination city
    float price;             // ticket price
    char time[10];           // departure time
};

// Global stuff ..basically predefined locations.. could have been done with user input but that would make this more complex
// like then need to manage a separate database then search for routes and seats.. just adding complexity..so no need :)
int seats[MAX_SEATS] = {0};  // 0 means empty seat, 1 means taken
struct route routes[MAX_ROUTES] = {
    {1, "Delhi", "Mumbai", 1200.0, "08:00"},
    {2, "Delhi", "Bangalore", 1500.0, "21:30"},
    {3, "Mumbai", "Pune", 300.0, "06:00"},
    {4, "Chennai", "Coimbatore", 800.0, "23:00"},
    {5, "Kolkata", "Bhubaneswar", 600.0, "19:30"},
    {6, "Delhi", "Hyderabad", 1800.0, "14:00"},
    {7, "Mumbai", "Chennai", 1000.0, "10:30"},
    {8, "Bangalore", "Kolkata", 1200.0, "09:00"},
    {9, "Hyderabad", "Delhi", 1600.0, "22:30"},
    {10, "Chennai", "Mumbai", 1400.0, "11:00"}
};

// Function declarations bcoz different compilers behave differently;
void show_welcome(void);
void setup_seats(void);
void show_all_routes(void);
void display_seat_map(void);
int book_multiple_seats(int *booked_seats, int count);
void clear_input(void);
int check_phone_number(char *phone);
int check_email_format(char *email);
int check_age_valid(int age);
void print_line(void);
void print_section_header(const char *title);

int main(void)
{
    // Main variables
    struct passenger passengers[MAX_PASSENGERS];
    int selected_route, num_passengers, booked_seats[MAX_PASSENGERS];
    int i, payment_choice;
    float total_cost = 0.0;
    char booking_ref[20];

    /*  generate random numbers for seat occupancy..
    i dont understand the syntax of srand it probably seeds from the current time..
    */
    srand(time(NULL));
    setup_seats();

    // Start the program
    show_welcome();

    // Step 1: Find out how many people are traveling
    do {
        printf("How many passengers will be traveling (1 to %d): ", MAX_PASSENGERS);
        scanf("%d", &num_passengers);
        if (num_passengers < 1 || num_passengers > MAX_PASSENGERS) {
            printf("Sorry, that's not valid. Please enter between 1 and %d.\n", MAX_PASSENGERS);
        }
    } while (num_passengers < 1 || num_passengers > MAX_PASSENGERS);
    clear_input();

    print_line();

    // Step 2: Get details for each passenger
    print_section_header("PASSENGER DETAILS");
    printf("Now I need some information about each passenger...\n\n");

    for (i = 0; i < num_passengers; i++) {
        printf("=== Passenger %d of %d ===\n", i + 1, num_passengers);

        // Get passenger name
        printf("Full Name: ");
        fgets(passengers[i].name, 50, stdin);
        passengers[i].name[strcspn(passengers[i].name, "\n")] = 0; // remove newline

        // Make sure name isn't too short
        while (strlen(passengers[i].name) < 2) {
            printf("Name seems too short. Please enter full name: ");
            fgets(passengers[i].name, 50, stdin);
            passengers[i].name[strcspn(passengers[i].name, "\n")] = 0;
        }

        // Get address
        printf("Address: ");
        fgets(passengers[i].address, 100, stdin);
        passengers[i].address[strcspn(passengers[i].address, "\n")] = 0;

        // Get age with checking
        do {
            printf("Age: ");
            scanf("%d", &passengers[i].age);
            if (!check_age_valid(passengers[i].age)) {
                printf("Invalid age! Please enter age between 1 and 100.\n");
            }
        } while (!check_age_valid(passengers[i].age));
        clear_input();

        // Get blood group
        printf("Blood Group (like A+, B-, O+ etc): ");
        fgets(passengers[i].blood_group, 5, stdin);
        passengers[i].blood_group[strcspn(passengers[i].blood_group, "\n")] = 0;

        // Get phone number with checking
        do {
            printf("Phone Number (10 digits only): ");
            fgets(passengers[i].phone, 15, stdin);
            passengers[i].phone[strcspn(passengers[i].phone, "\n")] = 0;
            if (!check_phone_number(passengers[i].phone)) {
                printf("Phone number should be exactly 10 digits!\n");
            }
        } while (!check_phone_number(passengers[i].phone));

        // Get email with basic checking
        do {
            printf("Email Address: ");
            fgets(passengers[i].email, 50, stdin);
            passengers[i].email[strcspn(passengers[i].email, "\n")] = 0;
            if (!check_email_format(passengers[i].email)) {
                printf("Email format doesn't look right. Please include @ and domain.\n");
            }
        } while (!check_email_format(passengers[i].email));

        // Get gender
        do {
            printf("Gender (M for Male, F for Female): ");
            scanf(" %c", &passengers[i].gender);
            passengers[i].gender = toupper(passengers[i].gender);
            if (passengers[i].gender != 'M' && passengers[i].gender != 'F') {
                printf("Please enter only M or F.\n");
            }
        } while (passengers[i].gender != 'M' && passengers[i].gender != 'F');
        clear_input();

        printf("Great! Passenger %d details saved.\n", i + 1);
        if (i < num_passengers - 1) printf("\n");
    }

    print_line();

    // Step 3: Choose route
    print_section_header("ROUTE SELECTION");
    printf("Here are all available routes:\n\n");
    show_all_routes();

    // Get route choice with validation
    do {
        printf("\nWhich route would you like (Enter ID 1-%d): ", MAX_ROUTES);
        scanf("%d", &selected_route);
        if (selected_route < 1 || selected_route > MAX_ROUTES) {
            printf("Invalid choice! Please select between 1 and %d.\n", MAX_ROUTES);
        }
    } while (selected_route < 1 || selected_route > MAX_ROUTES);
    clear_input();

    printf("Perfect! You selected: %s to %s\n",
        routes[selected_route - 1].from, routes[selected_route - 1].to);

    print_line();

    // Step 4: Choose seats
    print_section_header("SEAT SELECTION");
    printf("Time to pick your seats!\n");
    printf("Window seats (A & D columns) cost extra Rs.50\n");
    printf("Aisle seats (B & C columns) are standard price\n\n");

    display_seat_map();

    // Book seats for all passengers
    if (book_multiple_seats(booked_seats, num_passengers) == -1) {
        printf("Something went wrong with seat booking. Please try again.\n");
        return 1;
    }

    print_line();

    // Step 5: Calculate total cost
    printf("PRICE BREAKDOWN\n");
    printf("===============\n");
    total_cost = routes[selected_route - 1].price * num_passengers;
    printf("Base fare (%d passengers x Rs.%.0f): Rs.%.2f\n",
        num_passengers, routes[selected_route - 1].price, total_cost);

    // Add window seat charges
    float extra_cost = 0.0;
    for (i = 0; i < num_passengers; i++) {
        // Window seats are positions 1,4,5,8,9,12... (1st and 4th in each row)
        if (booked_seats[i] % 4 == 1 || booked_seats[i] % 4 == 0) {
            extra_cost += 50.0;
            printf("Window seat %d extra charge: Rs.50.00\n", booked_seats[i]);
        }
    }
    total_cost += extra_cost;
    printf("===============\n");
    printf("TOTAL AMOUNT: Rs.%.2f\n", total_cost);

    print_line();

    // Step 6: Payment
    print_section_header("PAYMENT");
    printf("Choose how you want to pay:\n\n");
    printf("1. Online Payment (Credit/Debit Card)\n");
    printf("2. Cash Payment (Pay at counter)\n");
    printf("3. UPI Payment (Phone Pe, Google Pay etc)\n\n");

    // Get payment choice
    do {
        printf("Select payment method (1, 2, or 3): ");
        scanf("%d", &payment_choice);
        if (payment_choice < 1 || payment_choice > 3) {
            printf("Please choose 1, 2, or 3 only.\n");
        }
    } while (payment_choice < 1 || payment_choice > 3);

    printf("\nProcessing your payment...\n");
    printf("Payment successful!\n");

    // Generate simple booking reference
    sprintf(booking_ref, "BUS%d%04d", (int)time(NULL) % 1000, rand() % 10000);

    print_line();

    // Step 7: Final confirmation
    print_section_header("BOOKING CONFIRMED!");
    printf("Your tickets have been booked successfully!\n\n");

    printf("Booking Reference: %s\n", booking_ref);
    printf("Date: %s", ctime(&(time_t){time(NULL)}));
    printf("Route: %s to %s\n", routes[selected_route - 1].from, routes[selected_route - 1].to);
    printf("Departure Time: %s\n", routes[selected_route - 1].time);
    printf("Total Passengers: %d\n", num_passengers);
    printf("Seat Numbers: ");
    for (i = 0; i < num_passengers; i++) {
        printf("%d", booked_seats[i]);
        if (i < num_passengers - 1) printf(", ");
    }
    printf("\nTotal Amount Paid: Rs.%.2f\n", total_cost);
    printf("Payment Method: %s\n",
        (payment_choice == 1) ? "Online" :
        (payment_choice == 2) ? "Cash" : "UPI");

    printf("\nPASSENGER LIST:\n");
    printf("---------------\n");
    for (i = 0; i < num_passengers; i++) {
        printf("%d. %s (Age: %d, Seat: %d, Gender: %c)\n",
            i + 1, passengers[i].name, passengers[i].age,
            booked_seats[i], passengers[i].gender);
    }

    print_line();
    printf("Thank you for booking with us!\n");
    printf("Please keep your booking reference safe.\n");
    printf("Have a safe and comfortable journey!\n");
    printf("==================================================\n");

    return 0;
}

// Show welcome message
void show_welcome(void)
{
    printf("\n");
    printf("==================================================\n");
    printf("        WELCOME TO BUS BOOKING SYSTEM            \n");
    printf("==================================================\n");
    printf("Book your bus tickets easily and quickly!\n");
    printf("==================================================\n\n");
}

// Set up some seats as occupied randomly
void setup_seats(void)
{
    int i, occupied_count = rand() % 10 + 5; // 5 to 15 seats occupied
    for (i = 0; i < occupied_count; i++) {
        seats[rand() % MAX_SEATS] = 1; // mark random seats as taken
    }
}

// Show all available routes in a table
void show_all_routes(void)
{
    int i;
    printf("+-----+--------------+--------------+--------------+--------------+\n");
    printf("| ID  |     FROM     |      TO      |    PRICE     |     TIME     |\n");
    printf("+-----+--------------+--------------+--------------+--------------+\n");

    for (i = 0; i < MAX_ROUTES; i++) {
        printf("| %-3d | %-12s | %-12s | Rs.%-9.0f | %-12s |\n",
            routes[i].id, routes[i].from, routes[i].to, routes[i].price, routes[i].time);
    }

    printf("+-----+--------------+--------------+--------------+--------------+\n");
}

// Show the bus seat layout
void display_seat_map(void)
{
    int i, row;
    printf("BUS SEAT LAYOUT:\n");
    printf("+--------------------------------------+\n");
    printf("|     A    B        C    D      DRIVER |\n");
    printf("+--------------------------------------+\n");

    for (row = 0; row < 10; row++) {
        printf("| %2d   ", row + 1);
        for (i = 0; i < 4; i++) {
            int seat_num = row * 4 + i;
            char status = seats[seat_num] ? 'X' : 'O'; // X = taken, O = free
            if (i == 2) printf("      "); // gap between left and right side
            printf("[%c] ", status);
        }
        printf("          |\n");
    }
    printf("+--------------------------------------+\n");
    printf("Legend: O = Available, X = Occupied\n");
    printf("Window seats (A,D): Scenic view (+Rs.50)\n");
    printf("Aisle seats (B,C): Easy access (no extra cost)\n");
}

// Book seats for multiple passengers
int book_multiple_seats(int *booked_seats, int count)
{
    int i, seat_num;
    char confirm;

    printf("\nLet's select seats for each passenger:\n");
    printf("--------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("\nSelecting seat for Passenger %d:\n", i + 1);

        do {
            printf("Enter seat number (1-40): ");
            scanf("%d", &seat_num);

            // Check if seat number is valid
            if (seat_num < 1 || seat_num > 40) {
                printf("Invalid seat! Please choose between 1-40.\n");
                continue;
            }

            // Check if seat is already taken
            if (seats[seat_num - 1] == 1) {
                printf("Sorry, seat %d is already taken! Try another.\n", seat_num);
                continue;
            }

            // Check if we already selected this seat for another passenger
            int j, already_picked = 0;
            for (j = 0; j < i; j++) {
                if (booked_seats[j] == seat_num) {
                    printf("Seat %d is already selected for another passenger!\n", seat_num);
                    already_picked = 1;
                    break;
                }
            }
            if (already_picked) continue;

            // Show seat details
            char seat_type = (seat_num % 4 == 1 || seat_num % 4 == 0) ? 'W' : 'A';
            printf("Seat %d: %s seat", seat_num,
                (seat_type == 'W') ? "Window (Rs.50 extra)" : "Aisle (standard price)");

            printf("\nConfirm seat %d for passenger %d? (y/n): ", seat_num, i + 1);
            scanf(" %c", &confirm);

            if (toupper(confirm) == 'Y') {
                seats[seat_num - 1] = 1; // mark seat as taken
                booked_seats[i] = seat_num;
                printf("Great! Seat %d booked for passenger %d.\n", seat_num, i + 1);
                break;
            } else {
                printf("Okay, let's pick a different seat.\n");
            }

        } while (1);
    }

    printf("\nAll seats booked successfully!\n");
    printf("Your seats: ");
    for (i = 0; i < count; i++) {
        printf("%d", booked_seats[i]);
        if (i < count - 1) printf(", ");
    }
    printf("\n");

    return 0;
}

// Check if phone number is valid (10 digits only)
int check_phone_number(char *phone)
{
    int i, len = strlen(phone);
    if (len != 10) return 0; // must be exactly 10 digits

    for (i = 0; i < len; i++) {
        if (!isdigit(phone[i])) return 0; // must be all numbers
    }
    return 1; // phone number is good
}

// Basic email format checking
int check_email_format(char *email)
{
    char *at_symbol = strchr(email, '@');
    char *dot = strrchr(email, '.');
    // Must have @ and . and @ should come before .
    return (at_symbol != NULL && dot != NULL && at_symbol < dot && strlen(email) > 5);
}

// Check if age is reasonable
int check_age_valid(int age)
{
    return (age >= 1 && age <= 120); // reasonable age range
}

// Clear input buffer - fixes scanf problems
void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Print a separator line
void print_line(void)
{
    printf("\n==================================================\n\n");
}

// Print section headers
void print_section_header(const char *title)
{
    printf("%s\n", title);
    printf("==================================================\n");
}
