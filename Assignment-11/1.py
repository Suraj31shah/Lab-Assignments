class RAG:
    def __init__(self):
        self.graph={}

    def add_node(self, node):
        if  node not in self.graph:
            self.graph[node]=[]

    def request_resource(self, process, resource):
        self.graph[process].append(resource)

    def assign_resource(self, resource, process):
        self.graph[resource].append(process)

    def detect_cycle(self):
        visited=set()
        rec_stack=set()

        def dfs(node):
            visited.add(node)
            rec_stack.add(node)

            for neighbor in self.graph.get(node, []):
                if neighbor not in visited:
                    if dfs(neighbor):
                        return True
                elif neighbor in rec_stack:
                    return True
                
            rec_stack.remove(node)
            return False
        
        for node in self.graph:
            if node not in visited:
                if dfs(node):
                    return True
                
        return False
    
rag=RAG()

p=int(input("Enter number of processes: "))
r=int(input("Enter number of resources: "))

print("Enter process names:")
for _ in range(p):
    proc=input()
    rag.add_node(proc)

print("Enter resource names:")
for _ in range(r):
    res=input()
    rag.add_node(res)

e=int(input("Enter number of edges: "))

print("\nEnter edges:")
print("Format:")
print("1 P R -> Process P requests Resource R")
print("2 R P -> Resource R assigned Process P")

for _ in range(e):
    data=input().split()

    if data[0]=='1':
        process=data[1]
        resource=data[2]
        rag.request_resource(process, resource)

    elif data[0]=='2':
        resource=data[1]
        process=data[2]
        rag.assign_resource(resource, process)

if rag.detect_cycle():
    print("\nDeadlock detected!")
else:
    print("\nNo deadlock")