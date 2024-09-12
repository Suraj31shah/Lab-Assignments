#include<stdio.h>
int main() {
    int n=0,i=0,max=0,second_max=0,temp=0;
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
    max=array[0];
    second_max=array[1];
    if (max<second_max) {
        temp=max;
        max=second_max;
        second_max=temp;
    }
    for (i=2; i<n; i++) {
        if (array[i]>max) {
            second_max=max;
            max=array[i];
        }
        else if (array[i]>second_max && array[i]!=max) {
            second_max=array[i];
        }
    }
    printf("\nThe Maximum=%d\n",max);
    printf("The Second Maximum=%d\n",second_max);
    return 0;
}