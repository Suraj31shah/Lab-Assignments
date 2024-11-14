#include <stdio.h>
int main() {
    int n;
    int m;
    scanf("%d %d",&n,&m);
    int a;
    int b;
    int k;
    int i;
    int jar[n];
    int sum=0;
    for (i=0; i<n; i++) {
        jar[i]=0;
    }
    while (m!=0) {
        scanf("%d %d %d",&a,&b,&k);
        for (i=a; i<=b; i++) {
            jar[i-1]+=k;
        }
        m--;
    }
    for (i=0; i<n; i++) {
        sum+=jar[i];
    }
    printf("%d",sum/n);
}