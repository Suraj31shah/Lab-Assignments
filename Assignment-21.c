#include<stdio.h>
int main() {
	int op;
	float n1,n2;
	printf("Enter an operaton\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
	scanf("%d",&op);
	printf("Enter two operands: ");
	scanf("%f%f",&n1,&n2);
	switch (op) {
		case 1:
			printf("%f + %f = %f",n1,n2,n1+n2);
			break;
		case 2:
			printf("%f - %f = %f",n1,n2,n1-n2);
			break;
		case 3:
			printf("%f * %f = %f",n1,n2,n1*n2);
			break;
		case 4:
			printf("%f / %f = %f",n1,n2,n1/n2);
			break;
		default:
			printf("Error! Operator is incorrect");
	}
}
