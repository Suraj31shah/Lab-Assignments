#include<stdio.h>
int main()
{
	float p,r,t,SI;
	printf("Enter principal amount: ");
	scanf("%f",&p);
	printf("Enter rate of interest: ");
	scanf("%f",&r);
	printf("Enter time: ");
	scanf("%f",&t);
	SI=(p*r*t)/100;
	printf("Simple Interest=%f",SI);
	return 0;
}
