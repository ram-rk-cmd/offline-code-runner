#include <stdio.h>

int main() {
    int n;
    printf("Enter rows: ");
    scanf("%d", &n);

    int totalRows = 2 * n - 1;

    for (int i = 1; i <= totalRows; i++) {          
        for (int j = 1; j <= n; j++) {

            if ((i <= n && j <= n - i + 1) ||
                (i > n && j <= i - n + 1)) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}
