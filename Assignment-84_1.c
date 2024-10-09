#include<stdio.h>
#include<string.h>
int main() {
    struct book_details {
        char title[100];
        char author[100];
        int pages;
        float price;
    } book1,book2,book3;
    strcpy(book1.title,"Famous Five");
    strcpy(book1.author,"Enid Blyton");
    book1.pages=200;
    book1.price=499;
    strcpy(book2.title,"Secret Seven");
    strcpy(book2.author,"Enid Blyton");
    book2.pages=240;
    book2.price=399;
    strcpy(book3.title,"Harry Potter");
    strcpy(book3.author,"J. K. Rowling");
    book3.pages=300;
    book3.price=599;
    printf("The Details of the Books are:\n");
    printf("Details of book 1:\n");
    printf("Name: %s\t Author: %s\t Number of pages= %d\t Price= %f\n",book1.title,book1.author,book1.pages,book1.price);
    printf("Details of book 2:\n");
    printf("Name: %s\t Author: %s\t Number of pages= %d\t Price= %f\n",book2.title,book2.author,book2.pages,book2.price);
    printf("Details of book 3:\n");
    printf("Name: %s\t Author: %s\t Number of pages= %d\t Price= %f",book3.title,book3.author,book3.pages,book3.price);
    return 0;
}