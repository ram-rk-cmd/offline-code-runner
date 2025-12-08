/*
 * Input Test Program
 * This program tests if stdin input works correctly.
 * It reads an integer and prints its square.
 */
#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    // If input piping works, this should read the number from the Input box
    if (scanf("%d", &num) == 1) {
        printf("\nYou entered: %d\n", num);
        printf("Square is: %d\n", num * num);
    } else {
        printf("\nFailed to read input!\n");
    }
    return 0;
}
