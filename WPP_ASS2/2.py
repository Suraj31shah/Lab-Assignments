products={}
while True :
    ch1=input("Do you want to add more elements?(y/n): ")
    if ch1=='Y' or ch1=='y' :
        name=input("Enter name of product: ")
        price=float(input("Enter price of product: "))
        products[name]=price
    else :
        break
while True :
    ch2=input("Do you want to search another element(y/n): ")
    if ch2=='Y' or ch2=='y' :
        findName=input("Enter name of product to find: ")
        if findName in products:
            print("Price of",findName,"is",products[findName])
        else :
            print("The product is not found")
    else :
        break