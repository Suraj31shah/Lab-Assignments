import math

class Vector2D:
    def __init__(self, x, y):
        self.x=x
        self.y=y

    def magnitude(self):
        return math.sqrt(self.x**2 + self.y**2)
    
    def angle_with_x_axis(self):
        return math.degrees(math.atan2(self.y, self.x))
    
    def distance(v1, v2):
        return math.sqrt((v1.x-v2.x)**2 + (v1.y-v2.y)**2)
    
    def dot_product(v1, v2):
        return v1.x*v2.x + v1.y*v2.y
    
    def cross_product(v1, v2):
        return Vector2D(
            v1.x*v2.y, 
            v2.x*v1.y
        )
    
    def __repr__(self):
        return f"Vector2D({self.x}, {self.y})"

    
    
class Vector3D(Vector2D):
    def __init__(self, x, y, z):
        super().__init__(x, y)
        self.z=z

    def magnitude(self):
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)
    
    def distance(v1, v2):
        return math.sqrt((v1.x-v2.x)**2 + (v1.y-v2.y)**2 + (v1.z-v2.z)**2)
    
    def dot_product(v1, v2):
        return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z
    
    def cross_product(v1, v2):
        return Vector3D(
            v1.y * v2.z - v1.z * v2.y,
            v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x
        )
    
    def __repr__(self):
        return f"Vector#D({self.x},{self.y},{self.z})"
    
    
v2d_1 = Vector2D(3, 4)
v2d_2 = Vector2D(1, 2)
print("2D Vector Distance:", Vector2D.distance(v2d_1, v2d_2))
print("2D Dot Product:", Vector2D.dot_product(v2d_1, v2d_2))
print("2D Cross Product:", Vector2D.cross_product(v2d_1, v2d_2))

v3d_1 = Vector3D(3, 4, 5)
v3d_2 = Vector3D(1, 2, 3)
print("3D Vector Distance:", Vector3D.distance(v3d_1, v3d_2))
print("3D Dot Product:", Vector3D.dot_product(v3d_1, v3d_2))
print("3D Cross Product:", Vector3D.cross_product(v3d_1, v3d_2))