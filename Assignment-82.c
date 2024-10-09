#include<stdio.h>
int calculate_ncr(int N, int R) {
    int a=N-R;
    int fact_N=1,fact_R=1,fact_a=1;
    for (int i=1; i<=N; i++) {
        fact_N*=i;
    }
    for (int i=1; i<=R; i++) {
        fact_R*=i;
    }
    for (int i=1; i<=a; i++) {
        fact_a*=i;
    }
    int NCR=fact_N/fact_R/fact_a;
    printf("NCR=%d",NCR);
}
int main() {
    int N,R;
    printf("Enter N: ");
    scanf("%d",&N);
    printf("Enter R: ");
    scanf("%d",&R);
    calculate_ncr(N,R);
    return 0;
}