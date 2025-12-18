#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int s = 0; s < n - i - 1; s++) {
            printf(" ");
        }
        for (int j = i; j >= 0; j--) {
            printf("%c", 'A' + j);
            if (j > 0)
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}
