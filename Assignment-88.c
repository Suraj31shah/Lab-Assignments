#include <stdio.h>
int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n],copy[n];
    int *ptr1=arr;
    int *ptr2=copy;
    printf("Enter %d elements:",n);
    for (i=0; i<n; i++) {
        scanf("%d",&(*(arr+i)));
    }
    for (i=0; i<n; i++) {
        *(ptr2+i)=*(ptr1+i);
    }
    printf("Copied Array is:\n");
    for (i=0; i<n; i++) {
        printf("%d\t",copy[i]);
    }
}

