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

int checkLoop(struct Node *head) {
    struct Node *slow=head, *fast=head;

    while(slow!=NULL && fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast) {
            return 1;
        }
    }
    return 0;
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
    if(checkLoop(head)) {
        printf("The linked list contains a loop.");
    }
    else {
        printf("The linked list does not contain any loop.");
    }
}