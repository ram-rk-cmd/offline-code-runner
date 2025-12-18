#include <stdio.h>

int main() {
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= (n - i) * 4; s++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
            if (j < i)
                printf("       ");
        }
        printf("\n");
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int s = 1; s <= (n - i) * 4; s++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
            if (j < i)
                printf("       ");
        }
        printf("\n");
    }

    return 0;
}
