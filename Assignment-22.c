#include<stdio.h>
int main() {
    int n,i;
    int factorial=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    if (n<0) {
    	printf("Error! Factorial of negative number doesn't exist.'");
	}
	else {
		for (i=1; i<=n; ++i) {
        factorial*=i;
    	}
    	printf("The factorial of %d is %d",n,factorial);
	}
}
