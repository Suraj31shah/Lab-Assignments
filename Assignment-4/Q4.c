#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; 
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int new_data) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=new_data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void insertAtFirst(struct Node **head, int new_data) {
    struct Node *newNode=createNode(new_data);
    newNode->next=*head;

    if(*head!=NULL) {
        (*head)->prev=newNode;
    }

    *head=newNode;
    printf("Inserted %d at the beginning\n",new_data);
}

void insertAtEnd(struct Node **head, int new_data) {
    struct Node *newNode=createNode(new_data);
    if(*head==NULL) {
        *head=newNode;
        printf("Inserted %d at the end\n",new_data);
        return;
    }

    struct Node *temp=*head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->prev=temp;
    printf("Inserted %d at the end\n",new_data);
}

struct Node* insertAtMiddle(struct Node *head, int new_data)
{
    struct Node *newNode = createNode(new_data);
    int count =0;
    struct Node *ptr = head;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    count /= 2;
    int n = 1;
    ptr = head;
    while(n < count)
    {
        ptr = ptr->next;
        n++;
    }
    newNode->prev = ptr;
    newNode->next = ptr->next;
    if(newNode->next != NULL)
    {
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;
    printf("Inserted %d at the middle.\n",new_data);
    return head;
}

void insertAfterNode(struct Node **head, struct Node * given_node, int new_data) {
    if(given_node==NULL) {
        printf("The given node cannot be null.\n");
        return;
    }

    struct Node *newNode=createNode(new_data);
    newNode->next=given_node->next;
    newNode->prev=given_node;

    if(given_node->next!=NULL) {
        given_node->next->prev=newNode;
    }
    given_node->next=newNode;

    printf("Inserted %d after node %d\n",new_data,given_node->data);
}

void display(struct Node *head) {
    if(head==NULL) {
        printf("The list is empty\n");
        return;
    }

    struct Node *temp=head;
    while(temp!=NULL) {
        printf("%d",temp->data);
        if(temp->next!=NULL) {
            printf("<->");
        }
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head=NULL;

    insertAtFirst(&head, 10);
    display(head);

    insertAtEnd(&head, 20);
    display(head);

    insertAtEnd(&head, 40);
    display(head);

    insertAtEnd(&head, 50);
    display(head);

    head=insertAtMiddle(head, 30);
    display(head);

    insertAfterNode(&head, head->next->next->next, 60);
    display(head);

}