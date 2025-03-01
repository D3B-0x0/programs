#include <stdio.h>
#include <math.h>

// Function to count the number of digits
int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;  // Remove last digit
        count++;
    }
    return count;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int temp = num, sum = 0, n = countDigits(num);

    while (temp > 0) {
        int digit = temp % 10;      // Get last digit
        sum += pow(digit, n);       // Raise to power & add
        temp /= 10;                 // Remove last digit
    }

    return sum == num;  // Return 1 if Armstrong, 0 otherwise
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("%d is an Armstrong number\n", num);
    else
        printf("%d is NOT an Armstrong number\n", num);

    return 0;
}

