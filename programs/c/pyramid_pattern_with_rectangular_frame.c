/*
    Program to print Pyramid Pattern within rectangular frame
    Input: n (e.g. 5)
    Output Pattern:
    *********** (Row 1: 2n+1 stars)
    ****   **** (Row 2: n-1 stars, 3 spaces, n-1 stars?) -> 4+3+4 = 11.
    ***     *** (Row 3: n-2 stars, 5 spaces, n-2 stars)
    **       **
    *         * (Row n+1: 1 star, 2n-1 spaces, 1 star)
    
    Logic:
    Row 1: Print 2*n + 1 stars.
    Rows 2 to n+1:
      i goes from 1 to n.
      Stars: n - i + 1
      Spaces: 2*i - 1  (Check: i=1 -> 1 space? No Row 2 has 3 spaces usually in these patterns... 
      Let's re-examine image sample for n=5.
      Row 2 has 4 stars. n=5. So n-1 stars.
      Spaces needed = (2n+1) - 2*(n-1) = 2n+1 - 2n + 2 = 3.
      Row 3: 3 stars (n-2). Spaces = 11 - 6 = 5.
      Formula for row r (2 to n+1):
         Stars = n - (r - 2); 
         Spaces = (2*n + 1) - 2*Stars;
         
    This covers top half. Assuming "frame" implies symmetry or just this shape inside a box?
    The text says "rectangular frame... encompass the pyramid".
    Sample output usually dictates.
    I will print the pattern as seen in the sample (Top block + closing row if frame requires).
    Usually these problems are symmetrical. I will include the bottom close if it makes a full frame.
    Given "Pyramid Pattern", sometimes it's just the top part.
    However, "rectangular frame" usually implies a full box.
    Row 1 is full.
    Last row seen is *       *.
    To make a frame, the bottom row should be full stars ***********.
    
    Let's implement:
    1. Full row.
    2. Loop for middle (decreasing stars).
    3. (Optional) Full row at bottom to close frame? I'll add it to be safe for "Frame".
    
    Input: n
    Output: Pattern
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int width = 2 * n + 1;
    
    for (int j = 0; j < width; j++) {
        printf("*");
    }
    printf("\n");
    
    for (int i = 1; i <= n; i++) {
        int stars = n - i + 1;
        int spaces = width - 2 * stars;
        
        for (int s = 0; s < stars; s++) printf("*");
        for (int sp = 0; sp < spaces; sp++) printf(" ");
        for (int s = 0; s < stars; s++) printf("*");
        
        printf("\n");
    }
    
    for (int j = 0; j < width; j++) {
        printf("*");
    }
    printf("\n");
    
    return 0;
}
