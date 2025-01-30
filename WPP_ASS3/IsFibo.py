T=int(input())
result=[]
while T>0 :
    N=int(input())
    fib1=0
    fib2=1
    nextfib=0
    isFib=0
    if N==0 :
        isFib=1
    while nextfib<N :
        nextfib=fib1+fib2
        fib1=fib2
        fib2=nextfib
    if nextfib==N :
        isFib=1
    if isFib==1 :
        result.append("IsFibo")
    else :
        result.append("IsNotFibo")
    T-=1
for i in result :
    print(i)