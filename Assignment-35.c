#include<stdio.h>
int main() {
    int num,rem;
    int sum=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    while (num>0 || sum>9) {
        if (num==0) {
            num=sum;
            sum=0;
        }
        rem=num%10;
        sum+=rem;
        num/=10;
    }
    printf("The required sum of digits is %d",sum);
    return 0;
}