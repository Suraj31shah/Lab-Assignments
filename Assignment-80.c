#include<stdio.h>
int print_fibonacci(int N) {
    int prev1=1,prev2=0;
    for (int i=1; i<=N; i++) {
        if (i>2) {
            int num=prev1+prev2;
            prev2=prev1;
            prev1=num;
            printf("%d\t",num);
        }
        if (i==1) {
            printf("%d\t",prev2);
        }
        if (i==1) {
            printf("%d\t",prev1);
        }
    }
}
int main() {
    int N;
    printf("Enter the number of terms: ");
    scanf("%d",&N);
    printf("The first %d terms of the Fibonacci Series are:\n",N);
    print_fibonacci(N);
    return 0;
}