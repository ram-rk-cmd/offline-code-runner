#include<stdio.h>
int main(){
    long long int bin_num ;
    int decimal_num = 0, base = 1, rem;
  
    printf("Enter a binary number (0's and 1's): ");
    scanf("%lld", &bin_num);
    long long int temp=bin_num;
    while(bin_num > 0){
        rem = bin_num % 10;
        decimal_num += rem * base;
        bin_num /= 10 ;
        base *= 2;
    }
    printf("The decimal equivalent of %lld is: %d",temp, decimal_num);

}