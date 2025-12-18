/*
    Program to reverse a 5 digit integer number
    This program prompts the user to enter a 5 digit integer number and then reverses the number and displays the reversed value.
*/

#include<stdio.h>
int main(){
    int num, rev=0;
    printf("Please enter an 5 digt integer number: ");
    scanf("%d", &num);
    if(num>9999&& num<100000){
    while(num != 0){
        int digit = num % 10; // Extract the last digit
        rev = rev * 10 + digit; // Append the digit to the reversed number
        num = num / 10; // Remove the last digit from the original number
    }  printf("Reversed Number: %d\n", rev);
    }
    else{
        printf("Please enter a number with 5 digits.\n");
        return 1;
    }

   
}