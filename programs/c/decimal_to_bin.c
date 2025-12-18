/*
    decimal to Binary Conversion
    This program converts a given decimal to its binary representation.
    It prompts the user to enter a decimal and then displays its binary value.
*/

#include<stdio.h>
int main(){
    int ch;
    printf("Please enter a decimal number:");
    scanf("%d",&ch);
    if(ch>=0){
        printf("The binary value of %d is: ",ch);
        for(int i=7;i>=0;i--){
            int bit=(ch>>i)&1;

            printf("%d",bit);
             }
        printf("\n");
    }
    else{
        printf("Please enter a valid decimal number.\n");
    }
}