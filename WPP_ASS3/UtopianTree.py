T=int(input())
result=[]
while T>0 :
    N=int(input())
    height=1
    if N==0 :
        height=1
    for i in range(1,N+1) :
        if i%2==0 :
            height+=1
        else :
            height*=2
    result.append(height)
    T-=1
for i in result :
    print(i)