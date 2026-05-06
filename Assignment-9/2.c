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

    int p;
    printf("\nEnter process number making request: ");
    scanf("%d", &p);

    if (p < 0 || p >= n) {
        printf("Invalid process number\n");
        return 0;
    }

    int request[m];
    printf("Enter request vector:\n");
    for (i=0; i<m; i++) {
        scanf("%d", &request[i]);
    }

    for (i=0; i<m; i++) {
        if (request[i]>need[p][i]) {
            printf("\nError: Request exceeds maximum need.\n");
            return 0;
        }
    }

    for (i=0; i<m; i++) {
        if (request[i]>avail[i]) {
            printf("\nResources not available. Process must wait.\n");
            return 0;
        }
    }

    int tempAvail[m], tempAlloc[n][m], tempNeed[n][m];

    for (i=0; i<m; i++)
        tempAvail[i]=avail[i];

    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            tempAlloc[i][j]=alloc[i][j];
            tempNeed[i][j]=need[i][j];
        }
    }

    for (i=0; i<m; i++) {
        avail[i]-=request[i];
        alloc[p][i]+=request[i];
        need[p][i]-=request[i];
    }

    int finish[n], safeSeq[n];
    int work[m];

    for (i=0; i<n; i++) {
        finish[i]=0;
    }

    for (i=0; i<m; i++) {
        work[i]=avail[i];
    }

    int count=0;

    while (count<n) {
        int found=0;

        for (i=0; i<n; i++) {
            if (finish[i]==0) {

                for (j=0; j<m; j++) {
                    if (need[i][j]>work[j]) {
                        break;
                    }
                }

                if (j==m) {
                    for (k=0; k<m; k++) {
                        work[k]+=alloc[i][k];
                    }

                    safeSeq[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }

        if (found==0) {
            for (i=0; i<m; i++)
                avail[i]=tempAvail[i];

            for (i=0; i<n; i++) {
                for (j=0; j<m; j++) {
                    alloc[i][j]=tempAlloc[i][j];
                    need[i][j]=tempNeed[i][j];
                }
            }

            printf("\nRequest cannot be granted (UNSAFE state).\n");
            return 0;
        }
    }

    printf("\nRequest can be granted.\nSafe sequence: ");
    for (i=0; i<n; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}