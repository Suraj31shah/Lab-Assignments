#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int num) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    newNode->next=NULL;
    return newNode;
}

struct Node *arrayToLinkedList(int arr[], int n) {
    struct Node *head=NULL;
    struct Node *temp=NULL;
    for(int i=0; i<n; i++) {
        struct Node *newNode=createNode(arr[i]);
        if(head==NULL) {
            head=newNode;
        }
        else {
            temp->next=newNode;
        }
        temp=newNode;
    }
    return head;
}

void displayList(struct Node *head) {
    struct Node *temp=head;
    if(!head) {
        printf("The list is empty\n");
        return;
    }
    printf("Linked List: ");
    while(temp!=NULL) {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    struct Node *head=arrayToLinkedList(arr,n);
    printf("\nArray copied to linked list successfully.\n");
    displayList(head);
    return 0;
}