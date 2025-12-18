#include<stdio.h>

int main(){
float hours;
printf("Enter the time taken by the worker (in hours):");
scanf("%f",&hours);
if(hours<2.0f){
    printf("Enter valid input.");
}
    (hours>=2.0f && hours<3.0f)? printf("The worker is highly efficient.") :
        (hours>=3.0f && hours<4.0f) ? printf("The worker is ordered to improve speed.") :
            (hours>=4.0f && hours<=5.0f) ? printf("The worker is given training to improve speed.")  :
                printf("The worker has to leave the company.");
}
