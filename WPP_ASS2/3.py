T=int(input())
result=[]
while T>0:
    N=int(input())
    numcopy=N
    count=0
    while N>0:
        dig=N%10
        if dig!=0 and numcopy%dig==0:
            count+=1
        N//=10
    result.append(count)
    T-=1
for i in result:
    print(i)
