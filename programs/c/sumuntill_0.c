#include<stdio.h>
int main(){
int num;
int sum=0;
do{
    scanf("%d",&num);
     if(num==0){
printf("Sum:%d ",sum);
break;
    }
    sum+=num;
}while(1);

}
