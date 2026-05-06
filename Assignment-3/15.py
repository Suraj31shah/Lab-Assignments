import numpy as np

a=np.array(list(map(float, input("Enter elements of first array separated by space: ").split())))
b=np.array(list(map(float, input("Enter elements of first array separated by space: ").split())))

if len(a)!=len(b):
    print("Error: Arrays must have the same length.")
else:
    distance=np.linalg.norm(a-b)
    print("Euclidean distance is:", round(distance, 4))