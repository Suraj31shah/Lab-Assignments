#include <stdio.h>
#include <string.h>
int main() {
    char str[100],revStr[100];
    char *ptr1=str,*ptr2=revStr;
    int i;
    printf("Enter a string: ");
    gets(str);
    while (*ptr1) {
        ptr1++;
    }
    while (ptr1>=str) {
        ptr1--;
        *ptr2=*ptr1;
        ptr2++;
    }
    printf("Copied String is: ");
    printf("%s",revStr);
}