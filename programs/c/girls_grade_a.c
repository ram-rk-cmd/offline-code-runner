/*
    Program to calculate the number of girls getting grade 'A'
    Total students = 90, Boys = 45. 
    50% of total students secured grade 'A'.
    Out of grade 'A' students, 20 are boys.
    Formula: Girls_A = (Total * 0.5) - Boys_A
    Input: None (Hardcoded as per problem statement)
    Output: Total number of girls getting grade 'A'
*/

#include <stdio.h>

int main() {
    int students = 90;
    int boys = 45;
    int gradeABoys = 20;
    
    int gradeA = students * 50 / 100;
    
    int gradeAGirls = gradeA - gradeABoys;
    
    printf("Expected Output: %d\n", gradeAGirls);
    
    return 0;
}
