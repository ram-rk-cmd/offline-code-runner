#include<stdio.h>

int fibonacci_series( int n){

int n1=0,n2=1,temp;
if (n == 0) return 0;
if (n == 1) return 1;
for(int i=2;i<=n;i++){
        temp=n1+n2;
        n1=n2;
        n2=temp;
}
return n2;

}

int main(){
    int num;
    printf("Enter value for n: ");
    scanf("%d",&num);
    int sum=fibonacci_series(num+2)-1;
    printf("Sum of Fibonacci numbers up to %d = %d\n", num, sum);
}
