#include<stdio.h>
int main()
{
    int m1,m2,m3,m4,m5,total;
    float perc;
    printf("Enter the marks of five subjects: ");
    scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
    total=m1+m2+m3+m4+m5;
    perc=total/5;
    if (perc>=60) {
    	printf("First division");
	}
	else if (perc>=50) {
    	printf("Second division");
	}
	else if (perc>=40) {
    	printf("Third division");
	}
	else {
    	printf("Fail");
	}
}
