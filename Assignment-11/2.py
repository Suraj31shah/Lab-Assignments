class RAG:
    def __init__(self):
        self.graph={}

    def add_node(self, node):
        if node not in self.graph:
            self.graph[node]=[]

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def is_cyclic_util(self, node, visited, rec_stack):
        visited.add(node)
        rec_stack.add(node)

        for neighbor in self.graph[node]:
            if neighbor not in visited:
                if self.is_cyclic_util(neighbor, visited, rec_stack):
                    return True
            elif neighbor in rec_stack:
                return True

        rec_stack.remove(node)
        return False

    def detect_deadlock(self):
        visited=set()
        rec_stack=set()

        for node in self.graph:
            if node not in visited:
                if self.is_cyclic_util(node, visited, rec_stack):
                    return True
        return False

rag = RAG()

p = int(input("Enter number of processes: "))
r = int(input("Enter number of resources: "))

print("Enter process names:")
for _ in range(p):
    rag.add_node(input())

print("Enter resource names:")
for _ in range(r):
    rag.add_node(input())

e=int(input("Enter number of edges: "))

print("\nEnter edges:")
print("Format:")
print("1 P R  -> Process P requests Resource R")
print("2 R P  -> Resource R assigned to Process P")

for _ in range(e):
    data=input().split()

    if data[0]=='1':
        rag.add_edge(data[1], data[2])
    elif data[0]=='2':
        rag.add_edge(data[1], data[2])

if rag.detect_deadlock():
    print("\nDeadlock detected!")
else:
    print("\nNo deadlock")