import re
s=input("Enter a string: ")
check=''
s=s.lower()
for i in s:
    if re.search('[a-z]',i) :
        check+=i
if len(set(check))==26 :
    print("Pangram")
else :
    print("Not a pangram")