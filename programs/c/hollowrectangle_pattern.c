#include<stdio.h>
int main(){
short int r,c;
scanf("%hd %hd",&r ,&c);
for(short int i=1;i<=r;i++){
    for(short int j=1;j<=c;j++){
        (i==1||i==r||j==1||j==c)?printf("*") : printf(" ");
    }
    printf("\n");
}
}
