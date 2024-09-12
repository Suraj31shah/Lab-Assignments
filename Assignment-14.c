#include<stdio.h>
int main() {
	char ch;
	printf("Enter a character: ");
	scanf("%c",&ch);
	if (ch>=65 && ch<=90) {
		printf("Capital Letter");
	}
	else if (ch>=97 && ch<=122) {
		printf("Small Case Letter");
	}
	else if (ch>=48 && ch<=57) {
		printf("Digit");
	}
	else {
		printf("Special Symbol");
	}
}
