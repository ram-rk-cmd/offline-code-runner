#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    int totalRows = 2 * n - 1;
    for (int i = 1; i <= totalRows; i++) {

        int stars = (i <= n) ? (2 * (n - i + 1) - 1) : (2 * (i - n + 1) - 1);

        int spaces = (totalRows - stars) / 2;
        for (int j = 1; j <= totalRows; j++) {
            if (j <= spaces || j > spaces + stars)
                printf("  ");
            else
                printf("* ");
        }
        printf("\n");
    }


}
