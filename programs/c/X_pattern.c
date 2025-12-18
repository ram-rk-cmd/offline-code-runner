#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int rows = 2 * n - 1;
    int cols = 2 * n - 1;

    for (int i = 1; i <= rows; i++) {
        int val = (i <= n) ? i : rows - i + 1;

        for (int j = 1; j <= cols; j++) {

            if (j == val || j == cols - val + 1) {
                printf("%d", val);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
