#include<stdio.h>
int main() {
int n;
printf("Enter size: ");
scanf("%d", &n);
int arr[n];
for(int i = 0; i < n; i++){
    printf("Enter number %d: ", i + 1);
    scanf("%d", &arr[i]);}
printf("Enter choice:\n ");
printf("1.Ascending Order\n2.Decending Order\n");
int choice;
scanf("%d",&choice);

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


if(choice == 1){
   int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    } }

//Decending
else if(choice==2){
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
else{
    printf("Invalid Choice");
}
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
