#include<stdio.h>
int main() {
    int num,rem;
    int rev=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    while (num>0) {
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    printf("The reverse of the given number is: %d",rev);
}