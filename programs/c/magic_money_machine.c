/*
    Program to calculate spending and final amount after magic money machine
    Anisha and Raja spend money on Apples and Bananas.
    Remaining balance is tripled by a magic machine.
    Formula: 
        Spent = AppleCost + BananaCost
        Balance = PocketMoney - Spent
        Deposited = Balance
        FinalAmount = Deposited * 3
    Input: Pocket Money, Apple Cost, Banana Cost
    Output: Spent Amount, Final Amount, Deposited Amount
*/

#include <stdio.h>

int main() {
    int pocketmoney, apple, banana;
    
    printf("Enter Pocket Money, Apple Cost, Banana Cost: ");
    if (scanf("%d %d %d", &pocketmoney, &apple, &banana) != 3) {
        printf("Invalid input.\n");
        return 1;
    }
    
    int spent = apple + banana;
    int balance = pocketmoney - spent;
    int deposited = balance;
    
    int finalAmount = deposited * 3;
    
    printf("%d\n", spent);
    printf("%d\n", finalAmount);
    printf("%d\n", deposited);
    
    return 0;
}
