#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int pri;
    struct Node *next;
}Node;

void enqueue(Node **head, int pri, int data) {
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->pri=pri;
    newNode->data=data;
    newNode->next=NULL;
    if (*head==NULL) {
        *head=newNode;
    }

    else if((*head)->pri<pri) {
        newNode->next=*head;
        *head=newNode;
        return;
    }

    else {
        Node *temp=*head;

        while (temp->next!=NULL && temp->next->pri>=pri) {
            temp=temp->next;
        }

        newNode->next=temp->next;
        temp->next=newNode;
        return;
    }
}

int isEmpty(Node *head) {
    if (head==NULL) {
        return 1;
    }
    return 0;
}

int dequeue(Node **head) {
    if (isEmpty(*head)) {
        printf("Queue is Empty\n");
        return -1;
    }
    Node *temp=*head;
    printf("%d deleted with priority %d", temp->data, temp->pri);
    *head=(*head)->next;
    free(temp);
}

int peek(Node **head) {
    if (isEmpty(*head)) {
        printf("Queue is Empty\n");
        return -1;
    }
    printf("The front element of the queue is %d", (*head)->data);
}

int main() {
    Node *head=NULL;
    int choice, data, pri;
    while (1) {
        printf("\nPriority Queue Operations:\n");
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
            printf("Enter priority: ");
            scanf("%d", &pri);
            enqueue(&head, pri, data);
            break;
        case 2:
            dequeue(&head);
            break;
        case 3:
            peek(&head);
            break;
        case 0:
            return 0;
        
        default:
            printf("Invalid choice!\n");
        }
    }
}