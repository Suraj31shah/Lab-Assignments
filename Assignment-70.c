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
    printf("The elements of the array are: ");
    for (i=0; i<n; i++) {
        printf("%d\t",arr[i]);
    }
    printf("\nEnter the element to be found: ");
    scanf("%d",&a);
    for (i=0; i<n; i++) {
        if (arr[i]==a) {
            found+=1;
        }
    }
    printf("The element %d occurs %d times",a,found);
    return 0;
}