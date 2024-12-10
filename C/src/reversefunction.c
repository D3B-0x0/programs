#include<stdio.h>
#include<string.h>

int isPalindrome(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    // Compare characters from the start and end
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }

    return 1; // Palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%99s", str); // Read up to 99 characters to avoid overflow

    if (isPalindrome(str)) {
        printf("Palindrome\n");
    } else {
        printf("NOT Palindrome\n");
    }

    return 0;
}

