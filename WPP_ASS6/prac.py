def greet(fx):
    def mfx():
        print("Good Morning")
        fx()
        print("Bye bye")
    return mfx

@greet
def hello():
    print("Hello World")

hello()