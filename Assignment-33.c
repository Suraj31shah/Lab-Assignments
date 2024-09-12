#include<stdio.h>
int main() {
    int n=0,i=0,max=0,min=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements:\n");
    for (i=0; i<n; i++) {
        scanf("%d",&array[i]);
    }
    printf("The array elements are: \n");
    for (i=0; i<n; i++) {
        printf("%d\t",array[i]);
    }
    min=array[0];
    max=array[1];
    for (i=0; i<n; i++) {
        if (array[i]>max) {
            max=array[i];
        }
        if (array[i]<min) {
            min=array[i];
        }
    }
    printf("\nThe Maximum=%d\n",max);
    printf("The Minimum=%d",min);
    return 0;
}