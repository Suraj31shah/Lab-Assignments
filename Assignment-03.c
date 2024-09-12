#include<stdio.h>
int main()
{
    int base,hra,other,gross;
    printf("Enter basic salary: ");
    scanf("%d",&base);
    printf("Enter HRA: ");
    scanf("%d",&hra);
    printf("Enter Other allowances: ");
    scanf("%d",&other);
    gross=base+hra+other;
    printf("Gross salary=%d",gross);
}

