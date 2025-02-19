class Queue:
    def __init__(self):
        self.items=[]

    def enqueue(self, item):
        self.items.append(item)
        print(f"Enqueued: {item}")

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty!")
            return None
        return self.items.pop(0)
    
    def is_empty(self):
        return len(self.items)==0
    
    def display(self):
        print("Queue:",self.items)

q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.display()
print(f"Dequeued: {q.dequeue()}")
q.display()