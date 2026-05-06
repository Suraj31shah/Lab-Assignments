import numpy as np

arr=np.array(list(map(int, input("Enter array elements separated by space: ").split())))

print("\nArray:")
print(arr)

peaks=np.where((arr[1:-1]>arr[:-2]) & (arr[1:-1]>arr[2:]))[0]+1

print("Peak positions:")
print(peaks)