#include <stdio.h>
struct members{
        int empno;
        char empname[100];
        float basepay;
    };
int main() {
    struct members emp[5];
    int i;
    for (i=0; i<5; i++) {
        printf("Enter employee number %d: ",i+1);
        scanf("%d",&emp[i].empno);
        printf("Enter employee name of employee %d: ",i+1);
        scanf("%s",&emp[i].empname);
        printf("Enter basic pay of employee %d: ",i+1);
        scanf("%f",&emp[i].basepay);
    }
    struct members *ptr=emp;
    for (i=0; i<5; i++) {
        printf("\nDetails of employee %d\n",i+1);
        printf("Employee No: %d",(*ptr).empno);
        printf("\nEmployee Name: ");
        puts((*ptr).empname);
        printf("Basic Pay: %f",(*ptr).basepay);
        ptr++;
    }
}