#include<stdio.h>
int check_palindrome(int num) {
    int rev=0;
    int rem,original;
    original=num;
    while (num>0) {
        rem=num%10;
        rev=rev*10+rem;
        num/=10;
    }
    return (rev==original);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if (check_palindrome(num)==1) {
        printf("The number is a palindrome");
    }
    else {
        printf("The number is not a palindrome");
    }
    return 0;
}