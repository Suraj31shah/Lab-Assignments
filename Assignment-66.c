#include<stdio.h>
int main() {
    int matrix1[3][3],matrix2[3][3],matrix3[3][3],i,j;
    int sum=0;
    printf("Enter the elements of matrix 1\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Enter the element at index(%d,%d): ",i,j);
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Enter the elements of matrix 2\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Enter the element at index(%d,%d): ",i,j);
            scanf("%d",&matrix2[i][j]);
        }
    }
    printf("The elements entered in the matrix 1 are:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d ",matrix1[i][j]);
        }
        printf("\n");
    }
    printf("The elements entered in the matrix 2 are:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d ",matrix2[i][j]);
        }
        printf("\n");
    }
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    printf("The elements of matrix 3 (matrix 1 + matrix 2) are:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d ",matrix3[i][j]);
        }
        printf("\n");
    }
    return 0;
}