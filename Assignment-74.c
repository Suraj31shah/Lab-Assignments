#include<stdio.h>
int main() {
    int n1,n2,i,j,a,b,c;
    printf("Enter the number of elements in Array A: ");
    scanf("%d",&n1);
    printf("Enter elements of Array A\n");
    int arrA[n1];
    for (i=0; i<n1; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arrA[i]);
    }
    printf("The elements of Array A before Sorting are: ");
    for (i=0; i<n1; i++) {
        printf("%d\t",arrA[i]);
    }
    printf("\nEnter the number of elements in Array B: ");
    scanf("%d",&n2);
    int arrB[n2];
    printf("Enter elements of Array B\n");
    for (i=0; i<n2; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arrB[i]);
    }
    printf("\nThe elements of Array B before Sorting are: ");
    for (i=0; i<n2; i++) {
        printf("%d\t",arrB[i]);
    }
    for (i=0; i<n1; i++) {
        for (j=i+1; j<n1; j++) {
            if (arrA[i]>arrA[j]) {
                a=arrA[i];
                arrA[i]=arrA[j];
                arrA[j]=a;
            }
        }
    }
    printf("\nThe elements of Array A after Sorting are: ");
    for (i=0; i<n1; i++) {
        printf("%d\t",arrA[i]);
    }
    for (i=0; i<n2; i++) {
        for (j=i+1; j<n2; j++) {
            if (arrB[i]>arrB[j]) {
                b=arrB[i];
                arrB[i]=arrB[j];
                arrB[j]=b;
            }
        }
    }
    printf("\nThe elements of Array B after Sorting are: ");
    for (i=0; i<n1; i++) {
        printf("%d\t",arrB[i]);
    }
    int arrC[n1+n2];
    for (i=0; i<n1; i++) {
        arrC[i]=arrA[i];
    }
    for (i=n1; i<(n1+n2); i++) {
        arrC[i]=arrB[i-n1];
    }
    printf("\nThe elements of Array C before Sorting are: ");
    for (i=0; i<(n1+n2); i++) {
        printf("%d\t",arrC[i]);
    }
    for (i=0; i<(n1+n2); i++) {
        for (j=i+1; j<(n1+n2); j++) {
            if (arrC[i]>arrC[j]) {
                c=arrC[i];
                arrC[i]=arrC[j];
                arrC[j]=c;
            }
        }
    }
    printf("\nThe elements of Array C after Sorting are: ");
    for (i=0; i<(n1+n2); i++) {
        printf("%d\t",arrC[i]);
    }
    return 0;
}