#include<stdio.h>
int main() {
    int n,i,a;
    int found=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for (i=0; i<n; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to find: ");
    scanf("%d",&a);
    for (i=0; i<n; i++) {
        if (arr[i]==a) {
            found=1;
            break;
        }
    }
    if (found==1) {
        printf("Element %d is present at the index %d",a,i);
    }
    else {
        printf("Element %d is not present in the array",a);
    }
    return 0;
}