#include<stdio.h>

int main(){
int n;
printf("Enter size of array:");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
        printf("Enter value %d: ",i+1);
        scanf("%d",&arr[i]);
}
int temp;
for(int i=0;i<n/2;i++){
        temp=arr[i];
        arr[i]= arr[n-i-1];
        arr[n-i-1]=temp;
}
for(int i=0;i<n;i++){
        printf("%d",arr[i]);
}

}


