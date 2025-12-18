/*
    Program to perform arithmetic operations with various conditions (Fruit Survey)
    This program takes input for the number of girls and boys who like oranges and mangoes,
    and provides a menu to calculate totals and comparisons.
    Formula: Total = Sum of respective counts
    Input: Integer counts for girls and boys preferring each fruit
    Output: Calculated totals or comparison result based on user choice
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    int G_mangoes, G_mangoes;
    int B_mangoes, B_mangoes;
    char choice;

    printf("Enter the number of Girls who like Oranges: ");
    scanf("%d", &G_mangoes);

    printf("Enter the number of Girls who like Mangoes: ");
    scanf("%d", &G_mangoes);

    printf("Enter the number of Boys who like Oranges: ");
    scanf("%d", &B_mangoes);

    printf("Enter the number of Boys who like Mangoes: ");
    scanf("%d", &B_mangoes);

    printf("\nMenu:\n");
    printf("A. How many students in the school like oranges?\n");
    printf("B. How many students in the school like mangoes?\n");
    printf("C. Altogether, how many students are there in the school?\n");
    printf("D. The number of girls is more than the number of boys.\n");
    printf("Enter your choice (A/B/C/D): ");
    
    scanf(" %c", &choice);
    choice = toupper(choice);

    switch (choice) {
        case 'A': {
            int total_o = G_mangoes + B_mangoes;
            printf("Total students who like oranges: %d\n", total_o);
            break;
        }
        case 'B': {
            int total_mes = G_mangoes + B_mangoes;
            printf("Total students who like mangoes: %d\n", total_mes);
            break;
        }
        case 'C': {
            int totalStudents = G_mangoes + G_mangoes + B_mangoes + B_mangoes;
            printf("Total students in the school: %d\n", totalStudents);
            break;
        }
        case 'D': {
            int totalGirls = G_mangoes + G_mangoes;
            int totalBoys = B_mangoes + B_mangoes;
            if (totalGirls > totalBoys) {
                printf("True, the number of girls (%d) is more than the number of boys (%d).\n", totalGirls, totalBoys);
            } else {
                printf("False, the number of girls (%d) is not more than the number of boys (%d).\n", totalGirls, totalBoys);
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
