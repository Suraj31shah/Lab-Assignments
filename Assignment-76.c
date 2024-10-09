#include<stdio.h>
void check_even(int num) {
    if (num%2==0) {
        printf("%d is even",num);
    }
    else {
        printf("%d is odd",num);
    }
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    check_even(num);
    return 0;
}