#include <stdio.h>
#include <string.h>
int main() {
    char *str;
    char *ptr=str;
    int excLength=0;
    int incLength;
    printf("Enter a string: ");
    gets(str);
    while(*ptr!='\0') {
        if (*ptr!=' ') {
            excLength++;
        }
        ptr++;
    }
    incLength=ptr-str;
    printf("Length of string including spaces=%d\n",incLength);
    printf("Length of string excluding spaces=%d",excLength);
}