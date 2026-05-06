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

int *linkedListToArray(struct Node *head, int *size) {
    *size=0;
    struct Node *temp=head;
    while(temp) {
        (*size)++;
        temp=temp->next;
    }
    int *arr=(int*)malloc((*size)*sizeof(int));
    temp=head;
    for(int i=0; i<*size; i++) {
        arr[i]=temp->data;
        temp=temp->next;
    }
    return arr;
}

void displayArray(int *arr, int size) {
    printf("\nArray: ");
    for(int i=0; i<size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
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
    int size;
    int *arr=linkedListToArray(head, &size);
    displayArray(arr, size);
    free(arr);
}