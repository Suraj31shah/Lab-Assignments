#include<stdio.h>
int main()
{
    int m1,m2,m3,m4,m5,total;
    float perc;
    printf("Enter the marks of five subjects: ");
    scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
    total=m1+m2+m3+m4+m5;
    perc=total/5;
    printf("Total marks=%d\n",total);
    printf("Percentage=%f",perc);
}

