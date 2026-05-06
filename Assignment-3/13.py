import numpy as np

arr=np.array(list(map(int, input("Enter array elements separated by space: ").split())))

print("\nOriginal Array:")
print(arr)

sorted_indices=np.argsort(arr)

print("Indices of the sorted elements of the given array:")
print(sorted_indices)