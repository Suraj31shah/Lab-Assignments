#include<stdio.h>
int main()
{
	int time,hr,min,sec;
	printf("Enter time in seconds: ");
	scanf("%d",&time);
	hr=time/3600;
	min=(time-(3600*hr))/60;
	sec=time-(3600*hr)-(60*min);
	printf("The converted time is %d hour, %d minutes and %d seconds",hr,min,sec);
}
