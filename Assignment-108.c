#include <stdio.h>
#include <string.h>
void str_copy() {
    char str[100],copyStr[100];
    int i;
    printf("Enter a string: ");
    fgets(str,100,stdin);
    for (i=0; str[i]!='\0'; i++) {
        copyStr[i]=str[i];
    }
    copyStr[i]='\0';
    printf("The copied string is: %s",copyStr);
}
void str_compare() {
    char str1[100],str2[100];
    int i,count=0;
    printf("Enter string 1: ");
    fgets(str1,100,stdin);
    printf("Enter string 2: ");
    fgets(str2,100,stdin);
    for (i=0; str1[i]!=0; i++) {
        if (str2[i]==str1[i]) {
            count++;
        }
    }
    if (count==strlen(str1)) {
        printf("The strings are equal");
    }
    else {
        printf("The strings are not equal");
    }
}
void str_concat() {
    char str1[100],str2[100];
    int i;
    printf("Enter string 1: ");
    fgets(str1,100,stdin);
    printf("Enter string 2: ");
    fgets(str2,100,stdin);
    int len=strlen(str1);
    for (i=0; str2[i]!='\0'; i++) {
        str1[len+i]=str2[i];
    }
    str1[len+i]='\0';
    printf("The final string 1 is: %s",str1);
}
void str_rev() {
    char str[100],rev_str[100];
    int i;
    printf("Enter a string : ");
    fgets(str,100,stdin);
    int len=strlen(str);
    for (i=0; str[i]!='\0'; i++) {
        rev_str[i]=str[len-i-1];
    }
    rev_str[i]='\0';
    printf("The reverse string is: %s",rev_str);
}
int main() {
    str_copy();
    str_compare();
    str_concat();
    str_rev();
}