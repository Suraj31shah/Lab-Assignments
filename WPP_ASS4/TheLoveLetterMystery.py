T=int(input())
result=[]
while T>0 :
    word=input()
    op=0
    length=len(word)
    for i in range(length//2) :
        op+=abs(ord(word[length-1-i])-ord(word[i]))
    result.append(op)
    T-=1
for i in result :
    print(i)