def deco_func(func) :
    def wrapper () :
        print("Before func")
        func()
        print("After func")
    return wrapper

@deco_func
def func_1() :
    print("Hello")
func_1()