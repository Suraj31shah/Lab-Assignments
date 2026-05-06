#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int num) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    newNode->next=NULL;
    return newNode;
}

void rotateLinkedList(struct Node **head, int k) {
    if(*head==NULL || k==0) {
        return;
    }
    struct Node *current=*head;
    while(current->next!=NULL) {
        current=current->next;
    }
    current->next=*head;
    current=*head;
    for(int i=1; i<k; i++) {
        current=current->next;
    }
    *head=current->next;
    current->next=NULL;
}

void displayList(struct Node *head) {
    while(head!=NULL) {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node *head=NULL;
    struct Node *temp=NULL;
    int n,num;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        printf("Enter the value of node %d: ",i+1);
        scanf("%d",&num);
        struct Node *newNode=createNode(num);
        if(head==NULL) {
            head=newNode;
        }
        else {
            temp->next=newNode;
        }
        temp=newNode;
    }
    printf("Original List:\n");
    displayList(head);
    int k;
    printf("Enter an integer to rotate the linked list counter clockwise: ");
    scanf("%d",&k);
    rotateLinkedList(&head,k);
    printf("Rotated List:\n");
    displayList(head);
}