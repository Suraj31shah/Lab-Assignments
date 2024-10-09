#include<stdio.h>
int check_armstrong(int num) {
    int rem,original;
    int sum=0;
    original=num;
    while (num>0) {
        rem=num%10;
        sum+=rem*rem*rem;
        num/=10;
    }
    return (sum==original);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if (check_armstrong(num)==1) {
        printf("The number is an armstrong number");
    }
    else {
        printf("The number is not an armstrong number");
    }
    return 0;
}