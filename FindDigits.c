#include <stdio.h>
int main() {
    int n;
    int num;
    int dig;
    int count=0;
    scanf("%d",&n);
    while (n!=0) {
        scanf("%d",&num);
        int numCopy=num;
        while (num>0) {
            dig=num%10;
            if (dig!=0) {
                if (numCopy%dig==0) {
                    count++;
                }
            }
            num/=10;
        }
        printf("%d\n",count);
        count=0;
        n--;
    }
}