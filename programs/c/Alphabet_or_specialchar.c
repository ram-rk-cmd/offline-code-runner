#include<stdio.h>
int main(){
   char ch ;
printf("Enter a character:");
scanf("%c",&ch);
(ch>= 'a' && ch<='z') ? 
printf(" \'%c\' is a lowercase alphabet. ",ch) : 
(ch>=33 && ch<=126 && !(ch>='A' && ch<='Z')) ? 
printf(" \'%c\' is a special character. ",ch) :
printf(" \'%c\' is not an alphabet or special character. ",ch);


}
