#include <stdio.h>
#define MAX_SIZE 1000000

int main() {
    int n, x;
    printf("Enter size: ");
    scanf("%d", &n);
    if (n > MAX_SIZE) {
        printf("Size exceeds limit of %d elements\n", MAX_SIZE);
        return 1;
    }

    int max, min;
    printf("Enter number 1: ");
    scanf("%d", &x);
    max = x;
    min = x;

    for (int i = 1; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &x);
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
        }
    }
    printf("Max: %d  Min: %d\n", max, min);
    return 0;
}