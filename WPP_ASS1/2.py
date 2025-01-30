import random

lst=[]
count_0=[]
count=0

for i in range(100):
    lst.append(random.randint(0,1))

print("List:",lst)

for num in lst:
    if num==0:
        count+=1
    else:
        count_0.append(count)
        count=0

print("The longest run of zeroes is",max(count_0))
