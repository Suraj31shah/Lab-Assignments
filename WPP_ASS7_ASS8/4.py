class Employee:
    def __init__(self, name, salary):
        self.name=name
        self.salary=salary
    
    def __add__(self, other):
        return self.salary+other.salary
    
    def __sub__(self, other):
        return abs(self.salary-other.salary)
    
e1 = Employee("Alice", 50000)
e2 = Employee("Bob", 60000)

combined = e1 + e2
print(combined)

salary_diff = e1 - e2
print(salary_diff)