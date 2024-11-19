#include <stdio.h>
int main() {
    FILE *fptr;
    fptr=fopen("Trial.txt","r");
    int word_count=1,char_count=0,line_count=0;
    char ch;
    ch=fgetc(fptr);
    while (ch!=EOF) {
        char_count++;
        if (ch==' ') {
            word_count++;
        }
        if (ch=='.') {
            line_count++;
        }
        ch=fgetc(fptr);
    }
    printf("The number of characters in the file are: %d\n",char_count);
    printf("The number of words in the file are: %d\n",word_count);
    printf("The number of lines in the file are: %d\n",line_count);
    fclose(fptr);
}