#include <stdio.h>

int main() {
    int age1, age2, age3;
    printf("Enter ages: ");
    scanf("%d", &age1);
    scanf("%d", &age2);
    scanf("%d", &age3);

    age1 > age2 && age1 > age3 ? printf("Choi Sung\n") :
    age2 > age1 && age2 > age3 ? printf("Moui Sung\n") :
                                 printf("Bhoi Sung\n");
    return 0;
}