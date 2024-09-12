#include<stdio.h>
int main() {
    int num=0;
    int sum=0;
    while (num>=0) {
        printf("Enter a number: ");
        scanf("%d",&num);
        if (num<0) {
            printf("Sum=%d",sum);
        }
        sum+=num;
    }
    return 0;
}