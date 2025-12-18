#include <stdio.h>

int main() {
    int n, count;
    printf("Enter n: ");
    scanf("%d", &n);

    int prev = n;
    int next = (n * 2) + (n - 2);
    int tc = n - 1;
    for (int i = n; i >= 1; i--) {

        if (i == 1) {
            for (count = 1; count <= (n * 2) + (n - 2); count++) {
                if (count == prev || count == next)
                    printf("*");
                else
                    printf(" ");
            }   }
        else {
            for (count = 1; count <= 2 * n * n; count++) {
                if (count == prev - tc || count == prev + tc ||
                    count == next - tc || count == next + tc)
                    printf("*");
                else
                    printf(" ");  }
            tc--;
        }
        printf("\n");
    }

    return 0;
}
