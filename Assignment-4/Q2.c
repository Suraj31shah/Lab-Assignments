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

void removeDuplicates(struct Node *head) {
    struct Node *current=head;
    struct Node *temp;
    struct Node *prev;
    while(current!=NULL) {
        prev=current;
        temp=current->next;

        while(temp!=NULL) {
            if(temp->data==current->data) {
                prev->next=temp->next;
                free(temp);
                temp=prev->next;
            }
            else {
                prev=temp;
                temp=temp->next;
            }
        }
        current=current->next;
    }
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
    removeDuplicates(head);
    printf("List after removing duplicate elements:\n");
    displayList(head);
}