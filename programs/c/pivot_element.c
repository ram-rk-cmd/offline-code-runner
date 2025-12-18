#include <stdio.h>

int sumofarr(int beg, int end) {
    int sum = 0;
    for (int i = beg; i <= end; i++) {
        sum += i;
    }
    return sum; }
int main() {
    int n;
    printf("Enter value for n: ");
    scanf("%d", &n);
    if (n <= 1) {
        printf("No integer pivot found\n");
        return 0; }
    int pivot = n - 1;
    int sum1, sum2;
    int found = 0;
    while (pivot > 1) {
        sum1 = sumofarr(1, pivot - 1);
        sum2 = sumofarr(pivot + 1, n);
        if (sum1 == sum2) {
            printf("Pivot element is: %d\n", pivot);
            found = 1;
            break;  }

        pivot--; }

    if (!found) {
        printf("No integer pivot found\n");
    }

}
