string_1="a,b,c,d"
lst=[]
for i in string_1[::-1] :
    if i==',':
        continue
    else :
        lst.append(i)
print(lst)