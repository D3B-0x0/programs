#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *input) {
    char buffer[10]; // Small buffer
    printf("Buffer address: %p\n", (void *)buffer);
    
    // No bounds checking
    strcpy(buffer, input); 
    
    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    printf("Demonstrating a buffer overflow...\n");
    vulnerableFunction(argv[1]);

    printf("Program completed without crashing (if input is safe).\n");
    return 0;
}

