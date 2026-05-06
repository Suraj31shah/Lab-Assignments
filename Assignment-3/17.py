import numpy as np

arr=np.array(list(map(int, input("Enter array elements separated by space: ").split())))

i=int(input("Enter the number to search: "))
n=int(input("Enter which occurerence to find: "))

indices=np.where(arr==i)[0]

if len(indices)<n:
    print(f"{i} foes not occur {n} times in the array")
else:
    print("Index of nth repetition:", indices[n-1])