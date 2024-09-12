#include<stdio.h>
int main() {
    int N;
    int even_sum=0,odd_sum=0,i;
    printf("Enter N: ");
    scanf("%d",&N);
    for (i=1; i<=N; i++) {
        if (i%2==0) {
            even_sum=even_sum+i;
        }
        else {
            odd_sum=odd_sum+i;
        }
    }
    printf("The sum of odd numbers upto %d is %d\n",N,odd_sum);
    printf("The sum of even numbers upto %d is %d",N,even_sum);
    return 0;
}