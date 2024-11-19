#include <stdio.h>
int main() {
    char str[100];
    char *ptr=str;
    int count=0;
    printf("Enter a string: ");
    gets(str);
    while (*ptr!='\0') {
        if (*ptr==' ') {
            count++;
        }
        ptr++;
    }
    printf("The number of words in the string are: %d",count+1);
}