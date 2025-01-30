n=int(input())
lst=[]
i=0
countSwap=0
lst = list(int(num) for num in input().strip().split())
# for i in range(n):
#     ele=int(input())
#     lst.append(ele)
for i in range(0,n-1):
    minIdx=i
    for j in range(i+1,n):
        if lst[j]<lst[minIdx]:
            minIdx=j
    if minIdx!=i:
        temp=lst[i]
        lst[i]=lst[minIdx]
        lst[minIdx]=temp
        countSwap+=1
print(countSwap)