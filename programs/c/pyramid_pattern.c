int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    int j = n;

    for (int i = 0; i < n; i++) {
        for (j= n; j >= i; j--) {
            printf(" ");
        }
        for(int k = 0 ;k <= i;k++){
                printf("* ");
            }
        printf("\n");
    }
    return 0;
}

