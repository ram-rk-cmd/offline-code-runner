#include <stdio.h>
#include <stdbool.h>

//bool ispowerof_2_bitwise(int n) {    return (n & (n - 1)) == 0; }

bool ispowerof_2_iterative(int n) {
    while (n > 1) {
        if (n % 2 != 0) {
            return false; }
        n /= 2;
    } return true;
}
int main() {
    int num;
    printf("Enter an integer: ");
    if(scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;}

    if (ispowerof_2_iterative(num)) {
        printf("%d is the power of 2\n", num);
    } else {
        printf("%d is not the power of 2\n", num);
    }
}
