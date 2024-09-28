#include<stdio.h>
int main() {
    int v,i,j;
    int count1=0,count2=0,count3=0,count4=0,count5=0,spoilt_balot=0;
    printf("Enter the number of voters:");
    scanf("%d",&v);
    printf("Voter! Enter your vote (1-5):\n");
    int vote[v];
    for (i=0; i<v; i++) {
        printf("Voter %d: ",i+1);
        scanf("%d",&vote[i]);
    }
    for (i=0; i<v; i++) {
        if (vote[i]==1) {
            count1+=1;
        }
        else if (vote[i]==2) {
            count2+=1;
        }
        else if (vote[i]==3) {
            count3+=1;
        }
        else if (vote[i]==4) {
            count4+=1;
        }
        else if (vote[i]==5) {
            count5+=1;
        }
        else {
            spoilt_balot+=1;
        }
    }
    printf("Candidate 1 got %d votes\n",count1);
    printf("Candidate 2 got %d votes\n",count2);
    printf("Candidate 3 got %d votes\n",count3);
    printf("Candidate 4 got %d votes\n",count4);
    printf("Candidate 5 got %d votes\n",count5);
    printf("Number of spoilt ballots=%d",spoilt_balot);
    return 0;
}