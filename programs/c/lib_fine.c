

#include<stdio.h>
int main(){
         int days;
         printf("Enter a number of days late:");
         scanf("%d",&days);

        if(days<=5){
        printf("The fine is:%.2f",days*0.5f) ;}

            else if(days>=6&&days<=10) {
                    days-=5;
//                    days*=1.0f;
            printf("The fine is:%.2f",2.5f+days) ; }

             else if(days>10 && days<=30) {
                    days-=10;days*=5.0f;printf("The fine is:%.2f",7.5f+days);}

                    else{
                       printf("Membership cancelled");
                    }
}
