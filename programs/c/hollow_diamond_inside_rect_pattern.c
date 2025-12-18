/*
    Program to generate a hollow diamond pattern inscribed within a hollow rectangle
    Input: n (half height of diamond). Height = 2*n + 1. Width = 2*n + 1.
    Output:
    Example n=5 (Width 11, Height 11).
    Hollow Rectangle border: Row 0, Row 2n, Col 0, Col 2n.
    Hollow Diamond border: |row - n| + |col - n| == n.
    Pattern: Print '*' if any condition is true, else space.
    
    Logic:
    Iterate row from 0 to 2*n.
      Iterate col from 0 to 2*n.
        Condition:
          Is Border: (row==0 || row==2*n || col==0 || col==2*n)
          Is Diamond: (abs(row - n) + abs(col - n) == n)
          If (Is Border OR Is Diamond) Print "* " (asterisk + space for visual aspect? 
              Sample output sparse dots usually imply simple "*".
              The problem says "spaces inside to create hollow effect". I will print just "*").
          Else Print " "
    
    However, the Sample Output visual in image `uploaded_image_2` is very sparse.
    It looks like:
    *         *         *
    *       *   *       *
    *     *       *     *
    
    If I print simply "*" and " ", it might be compressed. 
    Usually these patterns are single characters.
    
    Input: n
    Output: Pattern
*/

#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int size = 2 * n + 1;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int isBorder = (i == 0 || i == size - 1 || j == 0 || j == size - 1);
            int isDiamond = (abs(i - n) + abs(j - n) == n);
            
            if (isBorder || isDiamond) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
