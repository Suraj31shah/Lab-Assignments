class  Parent :
    def __init__(self):
        print("I am parent")
    
    def disp_class(self) :
        print(self.__class__)

class Child(Parent) :
    def __init__(self):
        super().__init__()
        print("I am child")

c=Child()