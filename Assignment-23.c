#include<stdio.h>
int main() {
	double base,exp;
	double result=1;
	int i;
	printf("Enter the base number: ");
	scanf("%lf",&base);
	printf("Enter the exponent number: ");
	scanf("%lf",&exp);
	for (i=1; i<=exp; ++i) {
		result=result*base;
	}
	printf("Result=%lf",result);
}
