#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *previous;
};

node* insertAtMiddle(node *head, int n)
{
    node *newNode = new node();
    newNode->data = n;
    int count =0;
    node *ptr = head;
    while(ptr != nullptr)
    {
        ptr = ptr->next;
        count++;
    }
        count /= 2;
        n = 1;
        ptr = head;
        while(n < count)
        {
            ptr = ptr->next;
            n++;
        }
       // ptr2->next = newNode;
        newNode->previous = ptr;
        newNode->next = ptr->next;
        if(newNode->next != nullptr)
        {
            ptr->next->previous = newNode;
        }
        ptr->next = newNode;
    return head;
}

int main()
{
    node *head = new node();
    node *sec = new node();
    head->data = 10;
    head->next =sec;
    head->previous = nullptr;
    sec->data = 15;
    sec->next = nullptr;
    sec->previous = head;
    head = insertAtMiddle(head,13);
    for(node *ptr = head;ptr;ptr=ptr->next)
    {
        cout << ptr->data << " ";
    }
}