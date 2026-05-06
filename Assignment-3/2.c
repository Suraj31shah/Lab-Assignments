#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *insertAtBegin(struct Node *head, int num) {
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=num;
    ptr->next=head;
    return ptr;
}

int main() {
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    struct Node *first=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->next=first;

    first->data=20;
    first->next=second;

    second->data=30;
    second->next=third;

    third->data=40;
    third->next=NULL;

    printf("Head Node: %d\n",head->data);
    printf("First Node: %d\n",first->data);
    printf("Second Node: %d\n",second->data);
    printf("Third Node: %d\n",third->data);

    insertAtBegin(head, 50);
}