#include <stdio.h>

int main() {
    int hardness;
    float carbon;
    int tensile;
    short int grade;

    printf("Enter hardness:");
    scanf("%d", &hardness);
    printf("Enter carbon:");
    scanf("%f", &carbon);
    printf("Enter tensile:");
    scanf("%d", &tensile);

    int con1 = (hardness > 50);
    int con2 = (carbon < 0.7f);
    int con3 = (tensile > 5600);

    grade = (con1 && con2 && con3) ? 10 :
            (con1 && con2)         ? 9  :
            (con2 && con3)         ? 8  :
            (con1 && con3)         ? 7  :
            (con1 || con2 || con3) ? 6  : 5;

    printf("Grade %d\n", grade);
    return 0;
}