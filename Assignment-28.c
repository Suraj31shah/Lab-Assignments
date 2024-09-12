#include<stdio.h>
int main() {
    int num,rem,original;
    int sum=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    original=num;
    while (num>0) {
        rem=num%10;
        sum+=rem;
        num=num/10;
    }
    if (sum==original) {
        printf("%d is an armstrong number",original);
    }
    else {
        printf("%d is not an armstrong number",original);
    }
}