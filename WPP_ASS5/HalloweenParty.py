T=int(input())
result=[]
while T>0 :
    K=int(input())
    vert=K//2
    if K%2 :
        result.append(vert*(vert+1))
    else :
        result.append(vert**2)
    T-=1
for i in result :
    print(i)