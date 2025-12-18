#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    char word[] = "RHOMBUS";
    int len = strlen(word);
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < i; s++) {
            printf(" ");  }
        if (i == 0 || i == n - 1) {
            for (int j = 0; j < len; j++) {
                printf("%c ", word[j]);  }
        } else {
            printf("%c", word[0]);
            for (int j = 0; j < (len - 1) * 2 - 1; j++) {
                printf(" ");
            }
            printf("%c", word[len - 1]);
        }
        printf("\n");
    }
}
