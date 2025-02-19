class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedList:
    def __init__(self):
        self.head=None

    def insert(self,data):
        new_node=Node(data)
        if not self.head:
            self.head=new_node
            return
        last=self.head
        while last.next:
            last=last.next
        last.next=new_node

    def delete(self, key):
        temp=self.head

        if temp and temp.data==key:
            self.head=temp.next
            temp=None
            return
        
        prev=None
        while temp and temp.data!=key:
            prev=temp
            temp=temp.next

        if not temp:
            return
        
        prev.next=temp.next
        temp=None

    def display(self):
        temp=self.head
        while temp:
            print(temp.data, end=' -> ')
            temp=temp.next
        print('None')

ll=LinkedList()
ll.insert(1)
ll.insert(2)
ll.insert(3)
ll.display()
ll.delete(2)
ll.display()