#include <stdio.h>
#include <stdlib.h>
int main() {
    int r1,r2,c1,c2,i,j,k;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d",&r2,&c2);
    if (c1!=r2) {
        printf("ERROR");
        return 1;
    }
    int **mat1=(int**)malloc(r1*sizeof(int*));
    int **mat2=(int**)malloc(r2*sizeof(int*));
    int **res=(int**)malloc(r1*sizeof(int*));
    for (i=0; i<r1; i++) {
        mat1[i]=(int*)malloc(c1*sizeof(int));
    }
    for (i=0; i<r2; i++) {
        mat2[i]=(int*)malloc(c2*sizeof(int));
    }
    for (i=0; i<r1; i++) {
        res[i]=(int*)malloc(c2*sizeof(int));
    }
    printf("Enter elements of Mat1:\n");
    for (i=0; i<r1; i++) {
        for (j=0; j<c1; j++) {
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Enter elements of Mat2:\n");
    for (i=0; i<r2; i++) {
        for (j=0; j<c2; j++) {
            scanf("%d",&mat2[i][j]);
        }
    }
    for (i=0; i<r1; i++) {
        for (j=0; j<c2; j++) {
            res[i][j]=0;
            for (k=0; k<c1; k++) {
                res[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    printf("Resultant Matrix:\n");
    for (i=0; i<r1; i++) {
        for (j=0; j<c2; j++) {
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
    for (i=0 ;i<r1; i++) {
        free(mat1[i]);
        free(res[i]);
    }
    for (j=0; j<r2; j++) {
        free(mat2[i]);
    }
    free(mat1);
    free(mat2);
    free(res);
}