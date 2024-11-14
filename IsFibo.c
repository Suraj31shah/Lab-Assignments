#include <stdio.h>
int main() {    
    int n;
    int isFib=0;
    int i,j;
    int num;
    int fib1=0;
    int fib2=1;
    int nextFib=0;
    scanf("%d",&n);
    while (n!=0) {
        scanf("%d",&num);
        while (nextFib<num) {
            nextFib=fib1+fib2;
            if (nextFib==num) {
                isFib=1;
            }
            fib1=fib2;
            fib2=nextFib;
        }
        if (isFib==1) {
            printf("IsFibo\n");
        }
        else {
            printf("IsNotFibo\n");
        }
        fib1=0;
        fib2=1;
        nextFib=0;
        isFib=0;
        n--;
    }
    return 0;
}