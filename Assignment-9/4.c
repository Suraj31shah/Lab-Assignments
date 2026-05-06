#include <stdio.h>

#define MAX 10

int n, m;
int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX];
int avail[MAX];

void calculateNeed() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
}

void enterData() {
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for (int i=0; i<m; i++) {
        scanf("%d", &avail[i]);
    }

    calculateNeed();
}

void displayNeed() {
    printf("\nNeed Matrix:\n");
    for (int i=0; i<n; i++) {
        printf("P%d: ", i);
        for(int j=0; j<m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int checkSafe() {
    int work[MAX], finish[MAX]={0}, safeSeq[MAX];

    for (int i=0; i<m; i++) {
        work[i]=avail[i];
    }

    int count=0;

    while (count<n) {
        int found=0;

        for (int i=0; i<n; i++) {
            if (!finish[i]) {
                int j;
                for (j=0; j<m; j++) {
                    if(need[i][j]>work[j]) {
                        break;
                    }
                }

                if (j == m) {
                    for(int k=0; k<m; k++) {
                        work[k]+=alloc[i][k];
                    }

                    safeSeq[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }

        if (!found) {
            printf("\nSystem is NOT in safe state\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state\nSafe sequence: ");
    for (int i=0; i<n; i++) {
        printf("P%d ", safeSeq[i]);
    }

    printf("\n");
    return 1;
}

void requestResources() {
    int p, request[MAX];

    printf("Enter process number: ");
    scanf("%d", &p);

    if (p<0 || p>=n) {
        printf("Invalid process number\n");
        return;
    }

    printf("Enter request vector:\n");
    for(int i=0; i<m; i++) {
        scanf("%d", &request[i]);
    }

    for (int i=0; i<m; i++) {
        if (request[i]>need[p][i]) {
            printf("Error: exceeds need\n");
            return;
        }
    }

    for (int i=0; i<m; i++) {
        if (request[i]>avail[i]) {
            printf("Resources not available\n");
            return;
        }
    }

    int tempAvail[MAX], tempAlloc[MAX][MAX], tempNeed[MAX][MAX];

    for (int i=0; i<m; i++) {
        tempAvail[i]=avail[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            tempAlloc[i][j]=alloc[i][j];
            tempNeed[i][j]=need[i][j];
        }
    }

    for (int i=0; i<m; i++) {
        avail[i]-=request[i];
        alloc[p][i]+=request[i];
        need[p][i]-=request[i];
    }

    if (checkSafe()) {
        printf("Request granted\n");
    } else {
        for (int i=0; i<m; i++) {
            avail[i]=tempAvail[i];
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                alloc[i][j]=tempAlloc[i][j];
                need[i][j]=tempNeed[i][j];
            }
        }

        printf("Request denied (unsafe)\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n--- BANKER'S ALGORITHM MENU ---\n");
        printf("1. Enter data\n");
        printf("2. Display Need matrix\n");
        printf("3. Check safe state\n");
        printf("4. Process resource request\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enterData(); break;
            case 2: displayNeed(); break;
            case 3: checkSafe(); break;
            case 4: requestResources(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}