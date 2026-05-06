#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void insertAtPosition(Node** head, int data, int pos) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (pos == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* temp = *head;
    for (int i = 1; temp->next != *head && i < pos; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteFromBeginning(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    *head = (*head)->next;
    last->next = *head;
    free(temp);
}

void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL) return;

    if (pos == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = *head, *prev = NULL;
    for (int i = 1; temp->next != *head && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) return;
    prev->next = temp->next;
    free(temp);
}

void deleteFromEnd(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    Node* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head->next);
    printf("(Repeat)\n");
}

int main() {
    Node *head=NULL;
    int choice, data, position;
    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at specific position\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Delete from specific position\n");
        printf("5. Delete first element\n");
        printf("6. Delete last element\n");
        printf("7. Display list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 5:
                deleteFromBeginning(&head);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                displayList(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}