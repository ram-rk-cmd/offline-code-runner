#include<stdio.h>
#include<string.h>
int main(){

char string1[20];
char string2[20];
printf("Enter string 1: ");
scanf("%s",string1);
printf("Enter string 2: ");
scanf("%s",string2);
//1
printf("1.Length of string1: %d\n",strlen(string1));
printf("  Length of string1: %d\n\n",strlen(string2));
//2
printf("2.Concatenate string2 to string1: %s\n\n",strcat(string1,string2));
//3
strcmp(string1,string2)==0? printf("3.Compare both strings: Same\n\n"):printf("3.Compare both strings: Different\n\n");
//4
char temp[20];
printf("4.Copy string2 to string1: %s\n\n",strcpy(temp,string2));
//5
for (int i = 0; string1[i] != '\0'; i++) {
        string1[i] = tolower(string1[i]);}
printf("5.To lowercase: %s\n\n",(string1));
//6
for (int i = 0; string2[i] != '\0'; i++) {
        string2[i] = toupper(string2[i]);}
printf("6.To uppercase: %s\n\n",string2);
//7
char temp1[50];
    strcpy(temp1, string1);
printf("7.Concatenate first character of string2 to string1: %s\n\n",strncat(temp1,string2,0));
//8
strncmp(string1,string2,2)==0? printf("8.Compare first 3 characters: Same\n\n"):printf("8.Compare first 3 characters: Different\n\n");
//9
printf("8.Copy the first n characters from string2 to string1: %s\n",strncpy(string1,string2,2));
}

