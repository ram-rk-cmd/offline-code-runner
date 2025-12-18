#include <stdio.h>

int main() {
    int width, height;
    printf("Width = ");
    scanf("%d", &width);
    printf("Height = ");
    scanf("%d", &height);

    for (int i = 1; i <= height; i++) {
        if ((i - 1) % 3 == 0) {   
            for (int j = 1; j <= width; j++) {
                printf("*\t");
            }
        } else {
            for (int j = 1; j <= width; j++) {
                if (j == 1 || j == width) {
                    printf("*\t");
                } else {
                    printf(" \t");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
