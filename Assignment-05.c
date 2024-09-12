#include<stdio.h>
int main()
{
	int a=5,b=10,c;
	printf("Before swapping: a=%d b=%d\n",a,b);
	c=a;
	a=b;
	b=c;
	printf("After swapping: a=%d b=%d\n",a,b);
}
