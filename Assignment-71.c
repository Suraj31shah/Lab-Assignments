#include<stdio.h>
int main() {
    int i;
    int arr[8]={6,7,8,1,2,3,4,5};
    printf("The elements of the array are: ");
    for (i=0; i<8; i++) {
        printf("%d\t",arr[i]);
    }
    for (i=0; i<8; i++) {
        if (arr[i]<arr[i+1]) {
            continue;
        }
        else { 
            break;
        }
    }
    printf("\nThe pivot is at index %d",i+1);
    return 0;
}