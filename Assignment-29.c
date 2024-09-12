#include<stdio.h>
int main() {
    int num,original,rem;
    int rev=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    original=num;
    while (num>0) {
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    if (rev==original) {
        printf("%d is a palindrom",original);
    }
    else {
        printf("%d is not a palindrom",original);
    }
}