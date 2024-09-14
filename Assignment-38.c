#include<stdio.h>
int main() {
    int n,i;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Square of numbers upto square of %d:\n",n);
    for (i=1; i<=n; i++) {
        printf("%d,",i*i);
    }
    return 0;
}