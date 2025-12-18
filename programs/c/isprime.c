/*
  Program to check whether a number is prime or not
  This program prompts the user to enter a positive integer and checks if it is a prime number or not.
*/
#include<stdio.h>
int main(){
    int num, isPrime=1;
    printf("Please enter a positive integer: ");
    scanf("%d", &num);
    if(num <= 1){
        printf("NO");}
    for(int i=2; i*i<=num; i++){
        if(num % i == 0){
            isPrime = 0;
            break;
        }  } 
    isPrime? printf("YES"): printf("NO");
    
}
