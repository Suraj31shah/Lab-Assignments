import math
import re
T=int(input())
result=[]
while T>0 :
    A,B=input().split()
    A=int(A)
    B=int(B)
    count=0
    for i in range(A,B+1) :
        sqr_root=str(math.sqrt(i))
        if  re.search('^\\d+\\.0$',sqr_root):
            count+=1
    result.append(count)
    T-=1
for i in result :
    print(i)