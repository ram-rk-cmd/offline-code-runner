#include<stdio.h>

int main(){
int r,c;
printf("No of rows:");
scanf("%d",&r);
printf("No of columns:");
scanf("%d",&c);
int arr[r][c] ;
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
            printf("Value for %d,%d: ",i,j);
        scanf("%d",&arr[i][j]);
    }
}
int pd ,sd;
pd=sd=0;
for(int i=0;i<r;i++){
    pd+=arr[i][i];
    sd+=arr[0][c-1];
    --c;
}
printf("Principal Diagonal: %d\nSecondary Diagonal: %d\n",pd,sd);
}


