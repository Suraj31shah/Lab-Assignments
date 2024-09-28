#include<stdio.h>
int main() {
    int roll_no[10],sub1[10],sub2[10],sub3[10],i,j,total[10],id1,id2,id3,id_total;
    printf("Enter the details and marks of the students:\n");
    for (i=0; i<10; i++) {
        printf("Enter roll number: ");
        scanf("%d",&roll_no[i]);
        printf("Enter subject 1 marks for roll number %d: ",roll_no[i]);
        scanf("%d",&sub1[i]);
        printf("Enter subject 2 marks for roll number %d: ",roll_no[i]);
        scanf("%d",&sub2[i]);
        printf("Enter subject 3 marks for roll number %d: ",roll_no[i]);
        scanf("%d",&sub3[i]);
    }
    int max1=sub1[0],max2=sub2[0],max3=sub3[0];
    printf("The marks of the students are:\n");
    for (i=0; i<10; i++) {
        printf("\nThe marks of roll number %d are:\n",roll_no[i]);
        printf("Sub1=%d\tSub2=%d\tSub3=%d\t",sub1[i],sub2[i],sub3[i]);
        total[i]=sub1[i]+sub2[i]+sub3[i];
    }
    int total_max=total[0];
    for (i=0; i<10; i++) {
        printf("\nThe total marks obtained by roll number %d are: ",roll_no[i]);
        printf("%d",total[i]);
    }
    for (i=0; i<10; i++) {
        if (sub1[i]>max1) {
            max1=sub1[i];
            id1=i;
        }
    }
    printf("\nThe highest marks in subject 1 are %d, secured by roll number %d",max1,roll_no[id1]);
    for (i=0; i<10; i++) {
        if (sub2[i]>max2) {
            max2=sub2[i];
            id2=i;
        }
    }
    printf("\nThe highest marks in subject 2 are %d, secured by roll number %d",max2,roll_no[id2]);
    for (i=0; i<10; i++) {
        if (sub3[i]>max3) {
            max3=sub3[i];
            id3=i;
        }
    }
    printf("\nThe highest marks in subject 3 are %d, secured by roll number %d",max3,roll_no[id3]);
    for (i=0; i<10; i++) {
        if (total[i]>total_max) {
            total_max=total[i];
            id_total=i;
        }
    }
    printf("\nThe highest total marks are %d, obtained by roll number %d",total_max,roll_no[id_total]);
    return 0;
}