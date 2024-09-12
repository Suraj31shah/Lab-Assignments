#include<stdio.h>
int main() {
    int n,i;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    int prev1=1;
    int prev2=0;
    printf("Fibonacci Series upto %d terms:\n",n);
    for (i=1; i<=n; i++) {
        if (i>2) {
            int num=prev1+prev2;
            prev2=prev1;
            prev1=num;
            printf("%d\t",num);
        }
        if (i==1) {
            printf("%d\t",prev2);
        }
        if (i==2) {
            printf("%d\t",prev1);
        }
    }
    return 0;
}