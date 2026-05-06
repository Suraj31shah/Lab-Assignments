import numpy as np

arr=np.array(list(map(float, input("Enter array elements separated by space: ").split())))

print("\nArray:")
print(arr)

percentiles=list(map(float, input("Enter percentile values: ").split()))

for p in percentiles:
    print(f"{int(p)}th percentile:", np.percentile(arr, p))