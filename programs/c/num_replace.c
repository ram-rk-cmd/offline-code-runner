
#include<stdio.h>
int main() {
    int arr[100];
    int n = 0;
    printf("Enter numbers (negative number to stop): \n");
    while(1) {
        int num;
        scanf("%d", &num);
        if(num < 0) {
            break;
        }
        arr[n++] = num;
    }

    printf("Original array: [");
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n - 1) {
            printf(" ");
        }
    }
    printf("]\n");

    for(int i = 0; i < n; i++) {
        int replacement = -1;
        if(arr[i] % 9 == 0) {
            replacement = 4;
        }
        if(arr[i] % 10 == 3) {
            replacement = replacement < 3 ? 3 : replacement;
        }
        if(arr[i] % 8 == 0) {
            replacement = replacement < 2 ? 2 : replacement;
        }
        if(arr[i] % 2 == 0) {
            replacement = replacement < 0 ? 0 : replacement;
        } else {
            replacement = replacement < 1 ? 1 : replacement;
        }
        arr[i] = replacement;
    }

    printf("Modified array: [");
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n - 1) {
            printf(" ");
        }
    }
    printf("]\n");

    return 0;
}
