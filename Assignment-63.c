#include<stdio.h>
int main() {
    int matrix[3][3],i,j;
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
    int min,max=matrix[0][0];
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            if (matrix[i][j] < min) { 
            min = matrix[i][j]; 
            } 
            if (matrix[i][j] > max) { 
                max = matrix[i][j]; 
            } 
        } 
    }
    printf("\nMaximum element=%d\n",max);
    printf("Minimum element=%d",min);
    return 0;
}