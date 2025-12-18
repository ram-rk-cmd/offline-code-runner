#include<stdio.h>
int main(){
short int num;
scanf("%hd",&num);
for(short int i=1; i<=20;i++){
   if(i==num) continue;
    printf("%-3hd",i);
    //num==i ? i+=0 :  printf("%-3hd",i);
}
}
