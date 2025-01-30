string_1="a,b,c,d"
substring="abc"
if substring not in string_1:
        print(-1)
else :
        for i in range(len(string_1)-len(substring),-1,-1) :
            if string_1[i:i+len(substring)]==substring:
                print(i)
                break

string_1=list(string_1)
substring=list(substring)
finalstring=''
n=int(input("Enter the number of times you want to replace: "))
count=0
for i in range(len(string_1)-len(substring)+1) :
    if(count==n) :
        break
    if string_1[i: i+len(substring)]==substring :
        string_1[i:i+len(substring)]="efg"
        count+=1
for c in string_1:
    finalstring+=c
print(finalstring)

# lst=[]
# for i in string_1 :
#     if i==',':
#         continue
#     else :
#         lst.append(i)
# print(lst)

lst=[]
for i in string_1[::-1] :
    if i==',':
        continue
    else :
        lst.append(i)
print(lst)