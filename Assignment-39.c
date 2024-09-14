#include <stdio.h>
int main() {
    int n,i;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for (i=1; i<n; i++) {
        printf("%d/%d!+",i,i);
    }
    printf("%d/%d!",n,n);
    return 0;
}