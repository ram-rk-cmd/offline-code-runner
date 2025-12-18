#include <stdio.h>

int main() {
    int num;
    printf("Enter a 4 digit number: ");
    scanf("%d", &num);
    if (num < 1000 || num > 9999) {
        printf("Invalid Input");
        return -1;    }
    int result = 0;
    int place = 1;

    while (num > 0) {
        int digit = num % 10;
        digit += 2;
        if (digit == 10) digit = 0; //for 8 -> 0
        else if (digit == 11) digit = 1; //for 9 ->1

        result = digit * place + result;
        place *= 10;
        num /= 10; }
    printf("%d", result);
}
