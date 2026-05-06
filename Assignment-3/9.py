import numpy as np

rows=int(input("Enter number of rows: "))
columns=int(input("Enter number of columns: "))

print("Enter elements row wise:")
elements=[]
for i in range(rows):
    row=list(map(int, input().split()))
    elements.append(row)

arr=np.array(elements)

print("\nOriginal array:")
print(arr)

print("\nSort along the first axis:")
arr=np.sort(arr, axis=0)
print(arr)

print("\nSort along the last axis:")
print(np.sort(arr, axis=1))