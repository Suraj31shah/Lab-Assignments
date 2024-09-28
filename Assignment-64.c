#include<stdio.h>
int main() {
    int matrix[3][3],i,j;
    int sum=0;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Enter the element at index(%d,%d): ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("The elements entered in the matrix are:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            sum+=matrix[i][j];
        }
        printf("Sum of the elements in row %d is %d\n",i,sum);
        sum=0;
    }
    return 0;
}