#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

void enqueue(Node **f, Node **r, int data) {
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if (*r==NULL) {
        *r=newNode;
        *f=newNode;
    }
    else {
        (*r)->next=newNode;
        *r=newNode;
        newNode->next=*f;
    }
}

int isEmpty(Node *f) {
    if (f==NULL) {
        return 1;
    }
    return 0;
}

int dequeue(Node **f, Node **r) {
    Node *temp=*f;
    if (isEmpty(*f)) {
        printf("Queue is Empty\n");
        return -1;
    }
    
    else {
        (*r)->next=(*f)->next;
        *f=(*f)->next;
        printf("Element deleted: %d", temp->data);
        free(temp);
    }
}

int peek(Node **f, Node **r) {
    if (isEmpty(*f)) {
        printf("Queue is Empty\n");
        return -1;
    }
    print("The front element of the queue is %d", (*f)->data);
}

int main() {
    Node *front=NULL;
    Node *rear=NULL;
    int choice, data;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(&front, &rear, data);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            peek(&front, &rear);
            break;
        case 0:
            return 0;
        
        default:
            printf("Invalid choice!\n");
        }
    }
}