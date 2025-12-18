#include<stdio.h>
#include<stdlib.h>
int main(){
short int month=2;
short int year=2000;
int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *months[] ={"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};
//printf("Enter month and year(Eg:2,2019): ");
//scanf("%hd, %hd",&month, &year);
if(month==2){
((year %4==0 && year % 100 != 0) || (year % 400==0)) ? printf("February %hd has 29 days",year) : printf("February %hd has 28 days",year);
}
else{
    printf("%s %hd has %d days",months[month-1],year,days[month-1]);
}


}
