import numpy as np

arr=np.array(list(map(float, input("Enter array elements separated by space: ").split())))

print("\nOriginal Array:")
print(arr)

rounded=np.round(arr)

print("\nRounded elements of the array to the nearest integer:")
print(rounded)

abs_values=np.abs(rounded)

print("\nAbsolute values after rounding:")
print(abs_values)