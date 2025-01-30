string_1=input("Enter a string: ")
result=''
for i in range(len(string_1)) :
    if i%2 :
        result+=string_1[i].upper()
    else :
        result+=string_1[i].lower()
print(result)