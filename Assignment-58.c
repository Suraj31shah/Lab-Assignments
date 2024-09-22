#include<stdio.h>
int main() {
    int arr1[10],arr2[10],arr3[10],i;
    printf("Enter elements of First Array\n");
    for (i=0; i<10; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr1[i]);
    }
    printf("Enter elements of Second Array\n");
    for (i=0; i<10; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr2[i]);
    }
    printf("The elements of first array are: ");
    for (i=0; i<10; i++) {
        printf("%d\t",arr1[i]);
    }
    printf("\nThe elements of second array are: ");
    for (i=0; i<10; i++) {
        printf("%d\t",arr2[i]);
    }
    for (i=0; i<10; i++) {
        arr3[i]=arr1[i]+arr2[i];
    }
    printf("\nThe elements of third array (first array + second array) are: ");
    for (i=0; i<10; i++) {
        printf("%d\t",arr3[i]);
    }
    return 0;
}