#include <stdio.h>

struct student {
    int roll;
    char name[100];
    float marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct student arr[n];

    for(int i=0; i<n; i++) {
        printf("Enter details of Student %d\n", i+1);
        printf("Enter roll number: ");
        scanf("%d",&arr[i].roll);
        printf("Enter name: ");
        scanf("%s",&arr[i].name);
        printf("Enter marks: ");
        scanf("%f",&arr[i].marks);
    }

    for(int i=0; i<n; i++) {
        printf("\nDetails of Student %d\n", i+1);
        printf("Roll no: %d\n",arr[i].roll);
        printf("Name: %s\n",arr[i].name);
        printf("Marks: %f\n",arr[i].marks);
    }
}
