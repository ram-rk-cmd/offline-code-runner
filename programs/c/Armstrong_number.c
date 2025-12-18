#include<stdio.h>
#include<math.h>
int main(){
int start,end;
printf("Enter Beginning and end range :");
scanf("%d %d",&start ,&end);
printf("Armstrong numbers between %d and %d are:\n", start, end);

for(int i=start ; i<=end ;i++){
    if(i<0) continue;

    int  digit=0;
    int temp =i;

     while(temp!=0){
        ++digit;
        temp/=10;
     }

    int sum = 0;
        int temp1 = i;
        while (temp1 != 0) {
            int num = temp1 % 10;
            sum += (int)round(pow(num, digit));
            temp1 /= 10;


    if(sum==i){
    printf("%-2d",sum);}
}

} }
