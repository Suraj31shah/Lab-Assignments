#include<stdio.h>
int main() {
    int x,n,Y,i;
    int result=1;
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Enter n: ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        Y=1+x;
        printf("Y(%d/%d)=%d",x,n,Y);
        break;

    case 2: 
        Y=1+x/n;
        printf("Y(%d/%d)=%d",x,n,Y);
        break;

    case 3:
        for (i=1; i<=n; ++i) {
            result*=x;
        }
        Y=1+result;
        printf("Y(%d/%d)=%d",x,n,Y);
        break;

    default:
        Y=1+n*x;
        printf("Y(%d/%d)=%d",x,n,Y);
        break;
    }
    return 0;
}