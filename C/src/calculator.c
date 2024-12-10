#include <stdio.h>

int main() {
    int num1, num2;
    char calc; // Use char to store the operator

    printf("Enter a number: ");
    scanf("%d", &num1);

    printf("Enter another number: ");
    scanf("%d", &num2);

    printf("Enter the operator you want to use (+, -, *, /): ");
    scanf(" %c", &calc); // Use " %c" to consume any leftover newline character

    if (calc == '+') {
        printf("The sum of two numbers is %d \n", num1 + num2);
    } else if (calc == '-') {
        printf("The difference between two numbers is %d \n", num1 - num2);
    } else if (calc == '*') {
        printf("The product of two numbers is %d \n", num1 * num2);
    } else if (calc == '/') {
        if (num2 == 0) {
            printf("Error: Division by zero is not allowed.\n");
        } else {
            printf("The quotient of two numbers is %d \n", num1 / num2);
        }
    } else {
        printf("Invalid operator. Please enter a valid operator (+, -, *, /).\n");
    }

    return 0;
}

