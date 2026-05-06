import numpy as np

array1 = np.array(list(map(int, input("Enter elements of Array1 separated by space: ").split())))
array2 = np.array(list(map(int, input("Enter elements of Array2 separated by space: ").split())))

print("Array1:", array1)
print("Array2:", array2)

result=np.isin(array1, array2)

print("Compare each element of array1 and array2")
print("Output:", result)