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
    for (i=0; i<n-1; i++) {
        int min_index=i;
        for (j=i+1; j<n; j++) {
            if (arr[j]<arr[min_index]) {
                min_index=j;
            }
        }
        if (min_index!=i) {
            temp=arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
        }
    }
    printf("The Aescending order of the array through selection sort:");
    for (i=0; i<n; i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}