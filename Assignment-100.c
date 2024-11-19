#include <stdio.h>
int main() {
    FILE *fptr;
    fptr=fopen("LNMIITSTUDENT.JAVA","w");
    struct student{
        int roll_no;
        char name[100];
        int total_marks;
    };
    int n,i;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct student arr[n];
    for (i=0; i<n; i++) {
        printf("Enter roll number: ");
        scanf("%d",&arr[i].roll_no);
        printf("Enter name: ");
        scanf("%s",arr[i].name);
        printf("Enter total marks: ");
        scanf("%d",&arr[i].total_marks);
    }
    for (i=0; i<n; i++) {
        fprintf(fptr,"%d\t",arr[i].roll_no);
        fprintf(fptr,"%s\t",arr[i].name);
        fprintf(fptr,"%d\t",arr[i].total_marks);
        fprintf(fptr,"\n");
    }
    fclose(fptr);
}