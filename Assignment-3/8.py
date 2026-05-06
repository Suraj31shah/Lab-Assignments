import numpy as np

arr1=np.array(list(map(int, input("Enter elements of 1-D array separated by space:").split())))
print("\nOriginal array:")
print(arr1)

unique1=np.unique(arr1)
print("Unique elements of the above array:")
print(unique1)

rows=int(input("\nEnter number of rows for 2-D array: "))
cols=int(input("\nEnter number of columns for 2-D array: "))

print("Enter elements row-wise:")
elements=[]
for i in range(rows):
    row=list(map(int, input().split()))
    elements.append(row)

arr2=np.array(elements)

print("\nOriginal array:")
print(arr2)

unique2=np.unique(arr2)
print("Unique elements of the above array:")
print(unique2)