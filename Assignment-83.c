#include<stdio.h>
int array_max(int n,int arr[n]) {
    int max=arr[0];
    for (int i=0; i<n; i++) {
        if (arr[i]>max) {
            max=arr[i];
        }
    }
    return max;
}
int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for (i=0; i<n; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The maximum element in the array is %d",array_max(n,arr));
    return 0;
}