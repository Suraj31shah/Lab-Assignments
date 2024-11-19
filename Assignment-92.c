#include <stdio.h>
int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    int *ptr=arr;
    printf("Enter %d numbers:\n",n);
    for (i=0; i<n; i++) {
        scanf("%d",ptr);
    }
    int max=ptr[0];
    for (i=0; i<n; i++) {
        if (*ptr>max) {
            max=*ptr;
        }
    }
    printf("The biggest number is: %d",max);
}