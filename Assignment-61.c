#include<stdio.h>
int main() {
    int n,i,j,temp;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for (i=0; i<n; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (arr[i]<arr[j]) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("The Aescending order of the array through bubble sort:");
    for (i=0; i<n; i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}