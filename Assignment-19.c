#include<stdio.h>
int main() {
	char ch;
	printf("Enter a character: ");
	scanf("%c",&ch);
	ch>=97 && ch<=122 ? printf("%c is a small case letter",ch) : printf("%c is  not a small case letter",ch);
}
