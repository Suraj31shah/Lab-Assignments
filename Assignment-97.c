#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int i;
    int count=0;
    printf("Enter a string: ");
    gets(str);
    char *ptr=str;
    while (*ptr!='\0') {
        if (*ptr=='A' || *ptr=='E' || *ptr=='I' || *ptr=='O' || *ptr=='U' || *ptr=='a' || *ptr=='e' || *ptr=='i' || *ptr=='o' || *ptr=='u') {
            count++;
        }
        ptr++;
    }
    printf("The number of vowels in the given string are: %d",count);
}