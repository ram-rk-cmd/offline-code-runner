#include<stdio.h>
/*#include<string.h>
int main(){
short int n;
printf("Enter Size of the array: ");
scanf("%hd",&n);
int arr[n];
short int max=0;
for(short int i=0;i<n;i++){
    printf("Enter element %hd: ",i+1);
    scanf("%d",&arr[i]);
    if(arr[i]>max){max=arr[i];}
}

int arr2[max+1];
memset(arr2, 0, sizeof(arr2));
for(short int i=0;i<n;i++){
        arr2[arr[i]]++;
}
short int index=-1;
int freq = 0;
for(short int i=0;i<=max;i++){
    if(arr2[i]>freq){freq=arr2[i]; index=i;}
}
(freq > n / 2)? printf("%d\nExplanation: Note that %d appears %d times which is more than %hd / 2 times.\n",index, index, freq, n):
        printf("-1 \nExplanation: There is no element whose frequency is greater than half of the array size.\n");

}
*/

int main() {
short int size;
printf("Enter Size of the array: ");
scanf("%hd",&size);
int arr[size];
for(short int i=0;i<size;i++){
    printf("Enter element %hd: ",i+1);
    scanf("%d",&arr[i]);
}
    int n = sizeof(arr) / sizeof(arr[0]);

     int majority = -1, count = 0;
    for(int i = 0; i < n; i++) {
        if(count == 0) {
            majority = arr[i];
            count = 1;
        } else if(arr[i] == majority) {
            count++;
        } else {
            count--; }
    }
    count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == majority) {
            count++;
        }
    }

    (count > n / 2)? printf("%d\nExplanation: Note that %d appears %d times which is more than %hd / 2 times.\n",majority, majority, count, n):
        printf("-1 \nExplanation: There is no element whose frequency is greater than half of the array size.\n");
}
