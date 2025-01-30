names=[]
rev_names=[]

print("Enter names of students: ")
for i in range(10):
    ele=input()
    ele=ele[:15]
    names.append(ele)

for i in names:
    rev_names.append(i[::-1])
    
print("The names of the students are: ",rev_names)