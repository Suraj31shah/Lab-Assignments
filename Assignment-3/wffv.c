#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to copy elements from an array to a linked list
struct Node* arrayToLinkedList(int arr[], int size) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 0; i < size; i++) {
        struct Node* newNode = createNode(arr[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (!head) {
        printf("The list is empty\n");
        return;
    }
    printf("Linked list: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = arrayToLinkedList(arr, n);

    printf("\nArray copied to linked list successfully.\n");
    displayList(head);

    return 0;
}