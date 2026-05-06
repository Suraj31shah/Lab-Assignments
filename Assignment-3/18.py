import numpy as np

arr=np.array(list(map(int, input("Enter array elements separated by space: ").split())))

print("\nOriginal Array:")
print(arr)

diff=np.diff(arr)

result=np.concatenate(([0, 0], diff, [200]))

print("\nDifference between neighboring elements, element-wise, and prepend [0, 0] and append [200]:")
print(result)