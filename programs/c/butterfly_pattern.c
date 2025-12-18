/*
    Program to print Butterfly Pattern
    Input: n (Rows in each half)
    Pattern (n=5):
    *        * (1 star, 8 spaces, 1 star)
    **      ** (2 stars, 6 spaces, 2 stars)
    ***    *** (3 stars, 4 spaces, 3 stars)
    ****  **** (4 stars, 2 spaces, 4 stars)
    ********** (5 stars, 0 space, 5 stars) -> Wait, logic 2*(n-i) spaces.
    Bottom Half (Mirror):
    **********
    ****  ****
    ***    ***
    **      **
    *        *
    
    Logic:
    Upper: i from 1 to n
      Stars: i
      Spaces: 2 * (n - i)
      Stars: i
    Lower: i from n down to 1
      Same logic.
      
    Wait, sample usually doesn't duplicate the middle row if it's "Butterfly".
    "Upper Half... Lower Half... combination both pascal triangles?"
    Sample output usually shows the middle row twice (once for top, once for bottom) to make the body thick.
    The snippet in `uploaded_image_3` shows:
    **********
    ********** (Two full rows? Or just one?)
    Usually Butterfly repeats the middle line for symmetry blocks. 
    Let's assume standard butterfly: 2n rows totals.
    
    Input: n
    Output: Pattern
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) printf("*");
        
        int spaces = 2 * (n - i);
        for (int j = 1; j <= spaces; j++) printf(" ");
        
        for (int j = 1; j <= i; j++) printf("*");
        
        printf("\n");
    }
    
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) printf("*");
        
        int spaces = 2 * (n - i);
        for (int j = 1; j <= spaces; j++) printf(" ");
        
        for (int j = 1; j <= i; j++) printf("*");
        
        printf("\n");
    }
    
    return 0;
}
