import sys

class Bankers:
    def __init__(self, resources, available, max_need):
        self.n=len(max_need)
        self.m=resources

        self.available=available[:]
        self.max_need=max_need
        self.allocation=[[0]*self.m for _ in range(self.n)]
        self.need=[row[:] for row in max_need]

    def is_safe(self):
        work=self.available[:]
        finish=[False]*self.n
        safe_seq=[]

        while len(safe_seq)<self.n:
            found=False
            for i in range(self.n):
                if not finish[i] and all(self.need[i][j]<=work[j] for j in range(self.m)):
                    for j in range(self.m):
                        work[j]+=self.allocation[i][j]
                    finish[i]=True
                    safe_seq.append(i)
                    found=True
            if not found:
                return False, []
        return True, safe_seq

    def request(self, pid, req):
        if any(req[j]>self.need[pid][j] for j in range(self.m)):
            print("Request exceeds process need")
            return

        if any(req[j]>self.available[j] for j in range(self.m)):
            print("Not enough resources available")
            return

        for j in range(self.m):
            self.available[j]-=req[j]
            self.allocation[pid][j]+=req[j]
            self.need[pid][j]-=req[j]

        safe, seq=self.is_safe()

        if safe:
            print("Request granted")
            print("Safe sequence:", ["P"+str(i) for i in seq])

            if all(self.need[pid][j]==0 for j in range(self.m)):
                print(f"Process P{pid} completed, releasing resources")
                for j in range(self.m):
                    self.available[j]+=self.allocation[pid][j]
                    self.allocation[pid][j]=0
        else:
            print("Request denied (unsafe state)")

            for j in range(self.m):
                self.available[j]+=req[j]
                self.allocation[pid][j]-=req[j]
                self.need[pid][j]+=req[j]

    def release(self, pid, rel):
        for j in range(self.m):
            rel[j]=min(rel[j], self.allocation[pid][j])
            self.available[j]+=rel[j]
            self.allocation[pid][j]-=rel[j]
            self.need[pid][j]+=rel[j]

        print("Resources released successfully")

filename=sys.argv[1]

with open(filename, 'r') as f:
    resources=int(f.readline())
    available=list(map(int, f.readline().split()))
    n=int(f.readline())

    max_need=[]
    for _ in range(n):
        max_need.append(list(map(int, f.readline().split())))

banker=Bankers(resources, available, max_need)

print("\nSystem Ready. Enter commands:")

while True:
    cmd=input("\nEnter request (pid a/r values) or 'exit': ")

    if cmd=="exit":
        break

    data=cmd.split()
    pid=int(data[0])
    action=data[1]
    values=list(map(int, data[2:]))

    if action=='a':
        banker.request(pid, values)
    elif action=='r':
        banker.release(pid, values)

    if all(all(banker.need[i][j]==0 for j in range(banker.m)) for i in range(banker.n)):
        print("\nAll processes completed. Exiting.")
        break