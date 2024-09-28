#include<stdio.h>
int main() {
    int ele,i,j,N,temp;
    printf("Enter the number of elements in Array: ");
    scanf("%d",&ele);
    printf("Enter elements of Array\n");
    int arr[ele];
    for (i=0; i<ele; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The elements of Array before rotating are: ");
    for (i=0; i<ele; i++) {
        printf("%d\t",arr[i]);
    }
    printf("Enter the number of positions to rotate: ");
    scanf("%d",&N);
    for (i=0; i<N; i++) {
        temp=arr[0];
        for (j=0; j<ele-1; j++) {
            arr[j]=arr[j+1];
        }
        arr[ele-1]=temp;
    }
    printf("The Array after rotating by %d positions is: ",N);
    for (i=0; i<ele; i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}