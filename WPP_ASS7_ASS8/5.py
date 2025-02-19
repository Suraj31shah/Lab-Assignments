import math

class Shape:
    def area(self):
        return 0
    
    def perimeter(self):
        return 0
    
class Rectangle(Shape):
    def __init__(self, width, height):
        self.width=width
        self.height=height

    def area(self):
        return self.width*self.height
    
    def perimeter(self):
        return 2*(self.width+self.height)
    
class Circle(Shape):
    def __init__(self, radius):
        self.radius=radius

    def area(self):
        return math.pi*self.radius**2
    
    def perimeter(self):
        return 2*math.pi*self.radius
    
rect = Rectangle(10, 5)
circ = Circle(7)

print(f"Rectangle Area: {rect.area()}, Perimeter: {rect.perimeter()}")
print(f"Circle Area: {circ.area()}, Perimeter: {circ.perimeter()}")
