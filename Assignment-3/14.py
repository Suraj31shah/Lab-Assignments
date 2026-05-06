import numpy as np

arr=np.array(list(map(int, input("Enter array elements separated by space: ").split())))

pos=int(input("Enter position partition: "))

print("\nOriginal Array:")
print(arr)

partitioned=np.partition(arr, pos)

print(f"After partitioning on position {pos}")
print(partitioned)