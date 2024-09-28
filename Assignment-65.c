#include<stdio.h>
int main() {
    int matrix[3][3],i,j,matrix_trans[3][3];
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
            matrix_trans[i][j]=matrix[j][i];
        }
    }
    printf("The transpose of the matrix is:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d ",matrix_trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}