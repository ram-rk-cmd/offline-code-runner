#include <stdio.h>

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int leaders[n];
    int index = 0;

    int max = arr[n - 1];
    leaders[index++] = max;

    for (int j = n - 2; j >= 0; j--) {
        if (arr[j] > max) {
            max = arr[j];
            leaders[index++] = max;
        }
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d ", leaders[i]);
    }
    return 0;
}