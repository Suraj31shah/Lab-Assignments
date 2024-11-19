#include <stdio.h>
#include <math.h>
int flip(int n, int x) {
    int div=pow(10,x);
    int last_x_digits=n%div;
    int remain_part=n/div;
    int rev=0;
    while (last_x_digits>0) {
        rev=rev*10+last_x_digits%10;
        last_x_digits/=10;
    }
    return remain_part*div+rev;
}
int main() {
    int n,x;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Enter number of digits to flip from end: ");
    scanf("%d",&x);
    printf("The flipped number is: %d",flip(n,x));
}