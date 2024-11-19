#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int *ptr=&n;
    printf("The square of number %d is %d\n",*ptr,*ptr**ptr);
    printf("The cube of number %d is %d",*ptr,*ptr**ptr**ptr);
}