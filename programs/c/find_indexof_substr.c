#include<stdio.h>

int find_substr(char *str ,char *substr){

    char *index = strstr(str,substr);
    int result;
    if(index!=NULL) result = index-str ;
    else result = -1;

    return result;
}

int main(){
    char substr[15];
    char str[100];
    printf("Enter string A: ");
    scanf("%s",substr);
    printf("Enter string B: ");
    scanf(" %[^\n]s",str);

    /*char *index = strstr(str,substr);
    (index!=NULL)?
//        printf("%s\n",index);
//        printf("%d\n",str);
       printf("Index: %ld",index-str):
       printf("-1";)
    */

    printf("Index: %d",find_substr(str,substr));
}
