import numpy as np

N=int(input("Enter the number of points: "))
cartesian_points=np.random.rand(N, 2)*20-10

x,y=cartesian_points[:,0], cartesian_points[:,1]
r=np.sqrt(x**2+y**2)
theta=np.arctan2(y,x)

polar_points=np.column_stack((r,theta))

print("Cartesian Coordinates(x, y):\n",cartesian_points)
print("Polar Coordinates(r, theta in radians):\n",polar_points)