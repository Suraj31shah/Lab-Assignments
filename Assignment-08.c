#include<stdio.h>
int main()
{
	int day,hr,min;
	day=31558150/(3600*24);
	hr=(31558150-(3600*24*day))/3600;
	min=(31558150-(3600*24*day)-(3600*hr))/60;
	printf("Earth takes %d days, %d hours and %d minutes to revolve around the Sun",day,hr,min);
}
