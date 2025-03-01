#include <stdio.h>

int main() {
    int a, b;
    char op;

    printf("Enter 2 numbers: ");
    scanf("%d %d", &a, &b);

    printf("Enter the operation you want to do (+ - * /): ");
    scanf(" %c", &op); // Space before %c to handle newline issues

    switch (op) {
        case '+':
            printf("Addition output: %d\n", a + b);
            break;
        case '-':
            printf("Subtraction output: %d\n", a - b);
            break;
        case '*':
            printf("Multiplication output: %d\n", a * b);
            break;
        case '/':
            if (b != 0)
                printf("Division output: %d\n", a / b);
            else
                printf("Error: Division by zero is not allowed!\n");
            break;
        default:
            printf("Please enter a valid operator (+, -, *, /)\n");
    }

    return 0;
}

