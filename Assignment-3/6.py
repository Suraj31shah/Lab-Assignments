def roux_array(n):
    arr=[]
    k=1

    while len(arr)<n:
        arr.append(k*k)
        if len(arr)<n:
            arr.append(0)
        k+=1

    return arr[::-1]

n=int(input("Enter the size of array:"))
print(roux_array(n))