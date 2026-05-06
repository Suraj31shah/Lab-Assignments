import numpy as np

# arr=np.array(list(map(int, input("Enter array elements separated by space: ").split())))
arr=np.array(list(map(float, input("Enter array elements (use nan for NaN) separated by space: ").split())))

# items=list(map(int, input("Enter items to count separated by space: ").split()))

print("\nOriginal array:")
print(arr)

# counts=[np.count_nonzero(arr==i) for i in items]

# print("Counts of specified items:")
# print(counts)

clean_arr=arr[~np.isnan(arr)]

print("After removing nan values:")
print(clean_arr)