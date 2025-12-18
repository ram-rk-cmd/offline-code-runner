#include<stdio.h>

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    for (int i = 1; i < n*2; i++) {
//        if(i <= n){
//        for(int k = 1 ;k <= i;k++){
//                printf("* ");
//            }}
//
//        else{
//        for (int j = 1; j <= (2 * n - i); j++) {
//                printf("* ");
//            }}


        int starts = (i <= n)? i : (2*n-i) ;

        for (int j = 1; j <= starts; j++) {
                printf("* ");
            }
                printf("\n");

        }}


