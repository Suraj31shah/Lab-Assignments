#include<stdio.h>
int main() {
    int n,i;
    int max=0,sec_max=0,temp=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for (i=0; i<n; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The entered numbers are: ");
    for (i=0; i<n; i++) {
        printf("%d\t",arr[i]);
    }
    max=arr[0];
    sec_max=arr[1];
    if (arr[1]>max) {
        temp=max;
        max=sec_max;
        sec_max=temp;
    }
    for (i=0; i<n; i++) {
        if (arr[i]>max) {
            sec_max=max;
            max=arr[i];
        }
        else if (arr[i]>sec_max && arr[i]!=max) {
            sec_max=arr[i];
        }
    }
    printf("\nThe Maximum=%d\n",max);
    printf("The Second Maximum=%d\n",sec_max);
    return 0;
}