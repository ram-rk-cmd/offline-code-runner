#include <stdio.h>
int main() {
    int cse, ece, mech;
    int max;
    printf("Enter the no of students placed in CSE:");
    scanf("%d", &cse);
    printf("Enter the no of students placed in ECE:");
    scanf("%d", &ece);
    printf("Enter the no of students placed in MECH:");
    scanf("%d", &mech);

    if (cse < 0 || ece < 0 || mech < 0) {
        printf("Input is Invalid\n");
    } else {
        max = cse;
        if (ece > max) {
            max = ece;
    }
        if (mech > max) {
            max = mech;
    }
        if (cse == max && ece == max && mech == max) {
            printf("None of the department has got the highest placement.\n");
        }
        else {

            printf("Highest placement:");


            if (ece == max) {
                if (cse == max) {
                    printf(" ");  }
                printf("ECE");   }

            if (mech == max) {
                if (cse == max || ece == max) {
                    printf(" ");  }
                printf("MECH");   }

            printf("\n");
    }

    }

}
