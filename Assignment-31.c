#include<stdio.h>
int main() {
    int num,rem;
    int sum=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    while (num>0)
    {
        rem=num%10;
        sum+=rem;
        num=num/10;
    }
    printf("The sum of digits of the  given number is %d",sum);    
}