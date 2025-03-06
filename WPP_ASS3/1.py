def digitalRoot(num) :
    sum=0
    newnum=0
    while num>0 :
        rem=num%10
        sum+=rem
        num//=10
    if sum>9 :
        newnum=sum
        return digitalRoot(newnum)
    return sum
        

def main() :
    num=int(input("Enter a number: "))
    print("The digital root of the number is:",digitalRoot(num))

if __name__=='__main__' :
    main()
