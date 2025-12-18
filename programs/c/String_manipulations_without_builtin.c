#include <stdio.h>

int main() {
    char str1[100], str2[100];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    // 1
    int len1 = 0, len2 = 0;

    while (str1[len1] != '\0') {
        len1++;
    }

    while (str2[len2] != '\0') {
        len2++;
    }

    printf("\n1. Length of string1: %d\n", len1);
    printf("   Length of string2: %d\n", len2);

    // 2
    int i = len1;
    int j = 0;

    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';

    printf("\n2. After concatenation: %s\n", str1);

    // 3
    int flag = 0;
    int k = 0;
    while (str1[k] != '\0' || str2[k] != '\0') {
        if (str1[k] != str2[k]) {
            flag = 1;
            break;
        }
        k++;
    }
    if (flag == 0)
        printf("\n3. Strings are SAME\n");
    else
        printf("\n3. Strings are DIFFERENT\n");

    // 4
    int c = 0;
    while (str2[c] != '\0') {
        str1[c] = str2[c];
        c++;
    }
    str1[c] = '\0';

    printf("\n4. After copying string2 into string1: %s\n", str1);

    return 0;
}
