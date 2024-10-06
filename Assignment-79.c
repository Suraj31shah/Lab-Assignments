#include<stdio.h>
int swap_var(int num1,int num2) {
    num1=num1^num2;
    num2=num1^num2;
    num1=num1^num2;
    printf("After swapping\n");
    printf("Number 1=%d\n",num1);
    printf("Number 2=%d",num2);
}
int main() {
    int num1,num2;
    printf("Enter number 1: ");
    scanf("%d",&num1);
    printf("Enter number 2: ");
    scanf("%d",&num2);
    swap_var(num1,num2);
    return 0;
}