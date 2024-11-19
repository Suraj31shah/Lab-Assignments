#include <stdio.h>
int main() {
    FILE *fptr;
    int count=0;
    char ch;
    fptr=fopen("Trial.txt","r");
    ch=fgetc(fptr);
    while (ch!=EOF) {
        if (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') {
            count++;
        }
        ch=fgetc(fptr);
    }
    printf("The number of vowels present in the file are: %d",count);
    fclose(fptr);
}