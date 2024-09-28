#include<stdio.h>
int main() {
    int n,i,temp;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for (i=0; i<n; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for (i=0; i<n/2; i++) {
        temp=arr[n-1-i];
        arr[n-1-i]=arr[i];
        arr[i]=temp;
    }
    printf("The reversed array is: \n");
    for (i=0; i<n; i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}