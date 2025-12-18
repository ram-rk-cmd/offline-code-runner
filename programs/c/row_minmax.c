#include<stdio.h>
int main() {
int r,c;
printf("Enter row size: ");
scanf("%d", &r);
printf("Enter col size: ");
scanf("%d", &c);

int arr[r][c];

for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
   printf("Value for %d,%d: ",i,j);
        scanf("%d",&arr[i][j]);
}
}
for(int i = 0; i < r; i++){
    int min = arr[i][0];
    int max = arr[i][0];

    for(int j = 1; j < c; j++){
        if(arr[i][j] < min){
            min = arr[i][j];
        }

        if(arr[i][j] > max){
            max = arr[i][j];
        }
    }

    printf("Row %d: Min = %d, Max = %d\n", i, min, max);

}
}
