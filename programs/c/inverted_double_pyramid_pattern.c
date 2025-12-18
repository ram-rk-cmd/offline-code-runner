/*
    Program to print Inverted Double Pyramid Pattern
    Input: n (e.g. 4)
    Output Pattern (for n=4):
    1234567 (1 to 2n-1)
     23456
      345
       4
      345
     23456
    1234567
    
    Logic:
    Upper Half (n rows):
    Row i (1 to n):
      Spaces: i-1
      Numbers: Start k=i. Print increasing k until k reaches 2n - i? No.
      Let's trace n=4.
      Row 1: i=1. Spaces 0. Print 1,2,3,4,5,6,7. (Start 1, End 7). End = 2*n - 1? 7.
      Row 2: i=2. Spaces 1. Print 2,3,4,5,6. (Start 2, End 6). End = 2*n - 2? 6.
      Row 3: i=3. Spaces 2. Print 3,4,5. (Start 3, End 5). End = 2*n - 3? 5.
      Row 4: i=4. Spaces 3. Print 4. (Start 4, End 4). End = 2*n - 4? 4.
      
      Loop j from i to (2*n - i). Print j.
      
    Lower Half (n-1 rows):
    Row i (n-1 down to 1):
      Same logic as above.
    
    Input: n
    Output: Pattern
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s < i; s++) {
            printf(" ");
        }
        for (int j = i; j <= (2 * n - i); j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    
    for (int i = n - 1; i >= 1; i--) {
        for (int s = 1; s < i; s++) {
            printf(" ");
        }
        for (int j = i; j <= (2 * n - i); j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    
    return 0;
}
