/*
    Program to print Fibonacci series in a square pattern
    Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, ...
    Pattern: Fill an n x n grid with the first n*n Fibonacci numbers.
    Formula: Fib(i) = Fib(i-1) + Fib(i-2)
    Input: Dimension n
    Output: Square pattern of Fibonacci numbers
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int total = n * n;
    
    long long t1 = 0, t2 = 1, next;
    
    long long terms[100]; 
    
    if (total > 100) {
        printf("N is too large for static array.\n");
        return 1;
    }
    
    for (int i = 0; i < total; ++i) {
        terms[i] = t1;
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld ", terms[i * n + j]);
        }
        printf("\n");
    }
    
    return 0;
}
