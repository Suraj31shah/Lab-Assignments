import numpy as np

arr=np.array(list(map(int, input("Enter array elements separated by space: ").split())))

print("\nOriginal Array:")
print(arr)

zero_indices=np.where(arr==0)[0]

print("Indices of elements equal to zero of the said array:")
print(zero_indices)