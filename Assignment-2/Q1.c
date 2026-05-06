#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **mat, int r, int c) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d",(*(mat+i)+j));
        }
    }
}

void computeProduct(int **mat1, int **mat2, int **res, int r1, int c1, int c2) {
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            *(*(res+i)+j)=0;
            for(int k=0; k<c1; k++) {
                *(*(res+i)+j)+=*(*(mat1+i)+k) * *(*(mat2+k)+j);
            }
        }
    }
}

void displayResMatrix(int **mat, int r, int c) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            printf("%d ",*(*(mat+i)+j));
        }
        printf("\n");
    }
}

int main() {
    int r1,r2,c1,c2;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d",&r2,&c2);
    if(r2!=c1) {
        printf("ERROR!");
        return 1;
    }

    int **mat1=(int**)malloc(r1*sizeof(int*));
    int **mat2=(int**)malloc(r2*sizeof(int*));
    int **res=(int**)malloc(r1*sizeof(int*));
    for(int i=0; i<r1; i++) {
        mat1[i]=(int*)malloc(c1*sizeof(int));
    }
    for(int i=0; i<r2; i++) {
        mat2[i]=(int*)malloc(c2*sizeof(int));
    }
    for(int i=0; i<r1; i++) {
        res[i]=(int*)malloc(c2*sizeof(int));
    }

    printf("Enter elements of Mat1:\n");
    readMatrix(mat1, r1, c1);
    printf("Enter elements of Mat2:\n");
    readMatrix(mat2, r2, c2);

    computeProduct(mat1, mat2, res, r1, c1, c2);

    printf("Resultant Matrix:\n");
    displayResMatrix(res, r1, c2);

    for (int i=0 ;i<r1; i++) {
        free(mat1[i]);
        free(res[i]);
    }
    for (int j=0; j<r2; j++) {
        free(mat2[j]);
    }
    free(mat1);
    free(mat2);
    free(res);
    return 0;
}
