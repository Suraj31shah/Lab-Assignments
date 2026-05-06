import numpy as np

rows, cols=4, 7
nola=np.zeros((rows, cols), dtype=int)

num=1
for i in range(rows):
    for j in range(cols):
        nola[i][j]=num
        num+=2
    num+=4

print(nola)