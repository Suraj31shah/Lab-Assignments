string_1="abcdabcdabcd"
substring="abc"
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