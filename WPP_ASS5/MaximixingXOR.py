L=int(input())
R=int(input())
lst=[]
for i in range (L,R+1) :
    for j in range (L,R+1) :
        lst.append(i^j)
print(max(lst))