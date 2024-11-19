#include <stdio.h>
int main() {
    int n=10;
    int *ptr;
    ptr=&n;
    printf("Value of n before modifying is %d\n",n);
    *ptr=20;
    printf("Value of n after modifying is %d",n);
}