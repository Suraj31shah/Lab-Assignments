string_1="abcdabcdabcd"
substring="cd"
count=0

st=int(input("Enter start index: "))
end=int(input("Enter end index: "))

for i in range(st, end-len(substring)) :
    if string_1[i:i+len(substring)]==substring :
        count+=1

print(count)