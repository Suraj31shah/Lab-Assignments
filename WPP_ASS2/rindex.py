string_1="abcdabcdabcd"
substring="cd"

st=int(input("Enter start index: "))
end=int(input("Enter end index: "))

for i in range(end,st,-1) :

    if substring not in string_1[st : end] :
        print("Error")
        break

    if string_1[i-len(substring)+1:i+1]==substring:
        print(i)
        break