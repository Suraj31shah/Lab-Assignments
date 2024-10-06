#include<stdio.h>
int check_prime(int num) {
    for (int i=2; i<num; i++) {
        if (num%i==0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int p=check_prime(num);
    if (p==1) {
        printf("The number is a prime number");
    }
    else {
        printf("The number is not a prime number");
    }
    return 0;
}