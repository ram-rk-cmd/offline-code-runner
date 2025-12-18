#include <stdio.h>

int main() {
    int n1, n2;
    printf("Enter 2 numbers:");
    scanf("%d", &n1);
    scanf("%d", &n2);
    ((n1 > 12 && n1 < 20) || (n2 > 12 && n2 < 20))
        ? printf("19")
        : printf("%d", n1 + n2);
    return 0;
}