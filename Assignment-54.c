#include<stdio.h>
int main() {
    int arr[10],i;
    int sum=0;
    for (i=0; i<10; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The numbers entered are: ");
    for (i=0; i<10; i++) {
        printf("%d\t",arr[i]);
        sum+=arr[i];
    }
    printf("\nThe sum of the elements of the array are: %d",sum);
    return 0;
}