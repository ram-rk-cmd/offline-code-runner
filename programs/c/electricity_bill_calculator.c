/*
    Program to calculate Electricity Bill for 30 days
    Data:
        - 2 Fans: 60W each, 6 hours/day
        - 3 Lights: 40W each, 8 hours/day
        - Other appliances: 3000W (interpreted as Wh) per day
        - Cost per unit: Rs. 6
    Formula: Total Wh = (Fans + Lights + Others) * 30 days
             Units (kWh) = Total Wh / 1000
             Bill = Units * Cost
    Input: None (Data given in problem)
    Output: Calculated Bill Amount
*/

#include <stdio.h>

int main() {
    int days = 30;
    float costPerunit = 6.0;
    
    float fan = 2 * 60 * 6;
    float light = 3 * 40 * 8;
    float others = 3000;
    
    float totalDailyWh = fan+ light + others;
    
    float totalMonthlyWh = totalDailyWh * days;
    
    float totalUnits = totalMonthlyWh / 1000.0;
    
    float bill = totalUnits * costPerunit;
    
    printf("Expected Output: %.1f\n", bill);
    
    return 0;
}
