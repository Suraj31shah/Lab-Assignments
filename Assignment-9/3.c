#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m];

    printf("\nEnter Allocation Matrix:\n");
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for (i=0; i<m; i++) {
        scanf("%d", &avail[i]);
    }

    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    printf("\n\nPROCESS\tALLOCATION\tMAX\t\tNEED\n");

    for (i=0; i<n; i++) {
        printf("P%d\t", i);

        for (j=0; j<m; j++) {
            printf("%d ", alloc[i][j]);
        }

        printf("\t\t");

        for (j=0; j<m; j++) {
            printf("%d ", max[i][j]);
        }

        printf("\t\t");

        for (j=0; j<m; j++) {
            printf("%d ", need[i][j]);
        }

        printf("\n");
    }

    printf("\nAvailable:\n");
    for (i=0; i<m; i++) {
        printf("%d ", avail[i]);
    }

    printf("\n");

    return 0;
}