num=input("Enter a number: ")
num=int(num)
fact=1
if num<0:
    print("Invalid number")
while num>=0:
    if num==0:
        fact*1
    else:
        fact*=num
    num-=1
print("Factorial=",fact)
