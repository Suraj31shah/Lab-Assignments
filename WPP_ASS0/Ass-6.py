num=input("Enter a number: ")
num=int(num)
rev=0
while num>0:
    rem=num%10
    rev=rev*10+rem
    num//=10
print("The reverse of the number is",rev)