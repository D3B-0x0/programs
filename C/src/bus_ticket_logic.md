# Bus Ticket Booking System

## Project Synopsis

A simple terminal-based bus ticket booking system implemented in C programming language. This system handles multiple passenger booking, seat selection with visual layout, and payment processing through a user-friendly command-line interface. The program is designed to work on any operating system without dependencies on special characters or external libraries.

## Project Overview

### Purpose
To create a straightforward console application that simulates the complete bus ticket booking process for multiple passengers, from registration to ticket confirmation, using only standard C libraries and ASCII characters for maximum compatibility.



## System Features

### 1. Multiple Passenger Booking
The system supports booking for up to 5 passengers in a single transaction:
- Collects individual details for each passenger
- Validates all input data with user-friendly error messages
- Assigns separate seats for each passenger
- Calculates total cost including extras

### 2. Comprehensive Passenger Information Collection
For each passenger, the system collects:
- **Name**: Full passenger name (minimum 2 characters)
- **Address**: Residential address
- **Age**: Passenger age (validated between 1-120 years)
- **Blood Group**: Emergency contact information (A+, B-, O+, etc.)
- **Phone Number**: 10-digit contact number with validation
- **Email**: Email address with basic format checking
- **Gender**: Male/Female for record keeping

### 3. Route Management System
#### Predefined Routes (10 Available)
1. Delhi → Mumbai (Rs.1200, 08:00)
2. Delhi → Bangalore (Rs.1500, 21:30)
3. Mumbai → Pune (Rs.300, 06:00)
4. Chennai → Coimbatore (Rs.800, 23:00)
5. Kolkata → Bhubaneswar (Rs.600, 19:30)
6. Delhi → Hyderabad (Rs.1800, 14:00)
7. Mumbai → Chennai (Rs.1000, 10:30)
8. Bangalore → Kolkata (Rs.1200, 09:00)
9. Hyderabad → Delhi (Rs.1600, 22:30)
10. Chennai → Mumbai (Rs.1400, 11:00)

#### Route Features
- Clear tabular display with proper alignment
- Price and timing information
- User-friendly route selection with validation

### 4. Advanced Seat Selection System
#### Visual Seat Layout
```
BUS SEAT LAYOUT:
+--------------------------------------+
|     A    B        C    D      DRIVER |
+--------------------------------------+
|  1   [O] [X]      [O] [O]           |
|  2   [X] [O]      [X] [O]           |
|  3   [O] [O]      [O] [X]           |
...
+--------------------------------------+
Legend: O = Available, X = Occupied
```

#### Seat Features
- Real-time visual representation using ASCII characters
- 40 total seats (10 rows × 4 seats per row)
- Window seats (A & D columns): +Rs.50 extra charge
- Aisle seats (B & C columns): Standard pricing
- Prevents double booking and seat conflicts
- Random initial seat occupancy for realism
- Seat confirmation before final booking

### 5. Payment Processing System
#### Payment Methods
- **Online Payment**: Credit/Debit Card simulation
- **Cash Payment**: Pay at counter option
- **UPI Payment**: Digital wallet simulation (PhonePe, GooglePay, etc.)

#### Payment Features
- Clear price breakdown display
- Automatic calculation of extra charges
- Payment method validation
- Success confirmation

### 6. Comprehensive Booking Confirmation
#### Summary Display
- Unique booking reference number
- Complete passenger details
- Journey information (route, date, departure time)
- Seat numbers for all passengers
- Total amount breakdown
- Payment method confirmation
- Formatted passenger list with seat assignments

## Technical Implementation

### Data Structures
```c
// Passenger information structure
struct passenger {
    char name[50];           // passenger name
    char address[100];       // residential address
    int age;                 // passenger age
    char blood_group[5];     // blood type
    char phone[15];          // contact number
    char email[50];          // email address
    char gender;             // M or F
};

// Route information structure
struct route {
    int id;                  // route identifier
    char from[30];           // departure city
    char to[30];             // destination city
    float price;             // base ticket price
    char time[10];           // departure time
};
```

### Core Functions
- `show_welcome()`: Display welcome banner
- `setup_seats()`: Initialize seat availability with random occupancy
- `show_all_routes()`: Display route table with proper formatting
- `display_seat_map()`: Visual ASCII seat layout
- `book_multiple_seats()`: Handle seat selection for multiple passengers
- `check_phone_number()`: Validate 10-digit phone numbers
- `check_email_format()`: Basic email format validation
- `check_age_valid()`: Age range validation (1-120 years)

### Input Validation Features
- Phone number: Exactly 10 digits, all numeric
- Email: Must contain @ and domain extension
- Age: Reasonable range (1-120 years)
- Name: Minimum 2 characters
- Gender: Only M or F accepted
- Seat selection: Range checking and availability verification
- Payment method: Valid option selection (1-3)

### Program Flow
1. **Welcome Screen** → System introduction
2. **Passenger Count** → Determine number of travelers
3. **Passenger Registration** → Collect details for each passenger
4. **Route Selection** → Choose from 10 available routes
5. **Seat Selection** → Visual seat map and individual seat booking
6. **Price Calculation** → Base fare + window seat extras
7. **Payment Processing** → Choose and confirm payment method
8. **Booking Confirmation** → Complete summary with reference number

## User Experience Design

### OS Compatibility
- Pure ASCII characters for universal compatibility
- No Unicode or special characters
- Works on Windows, Linux, macOS terminals
- Simple box-drawing using `+`, `-`, `|` characters

### Error Handling
- Graceful handling of invalid inputs
- Clear explanation of what went wrong
- Retry options for incorrect entries
- Prevention of program crashes

## Sample User Journey

1. **Start**: "Welcome to Bus Booking System"
2. **Input**: "How many passengers will be traveling (1 to 5): 2"
3. **Registration**: Collect details for each passenger with validation
4. **Route**: Display route table → User selects route ID
5. **Seats**: Show seat map → Select seats for each passenger
6. **Payment**: Calculate total → Choose payment method
7. **Confirmation**: "Booking Reference: BUS123456" with complete summary

## Key Features Summary

### Multiple Passenger Support
- Up to 5 passengers per booking
- Individual seat selection for each passenger
- Comprehensive details collection
- Prevents seat conflicts between passengers

### Robust Validation
- Phone number format checking
- Email validation
- Age range verification
- Seat availability confirmation
- Input sanitization and error handling

### Professional Interface
- Clean ASCII table formatting
- Visual seat layout representation
- Clear section headers and separators
- Conversational user interaction

### Cross-Platform Compatibility
- Standard C libraries only
- ASCII character usage
- No external dependencies
- Works on any C compiler and OS

## Development Specifications

### Code Organization
- Simple, beginner-friendly comments
- Clear variable naming conventions
- Modular function design
- Human-readable error messages

### Memory Management
- Static arrays for simplicity
- No dynamic memory allocation
- Safe string handling with bounds checking
- Buffer overflow prevention

### Compilation
```bash
gcc -o bus_booking bus_booking.c
./bus_booking
```


---

*This bus ticket booking system demonstrates practical C programming concepts including structures, arrays, functions, input validation, and user interface design in a real-world application context.*
