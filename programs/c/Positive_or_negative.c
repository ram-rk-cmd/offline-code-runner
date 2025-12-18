#include <stdio.h>

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    num < 0 ? printf("Negative") :
    num == 0 ? printf("Zero") :
               printf("Positive");
    return 0;
}