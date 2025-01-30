len=int(input("Enter a length in feet: "))

print("\nConvert Into:")
print("1.Inches")
print("2.Yards")
print("3.Miles")
print("4.Millimeters")
print("5.Centimeters")
print("6.Meters")
print("7.Kilometers\n")
ch=int(input("Enter your choice: "))

lst=[12,1/3,0.0001893939,304.8,30.48,0.3048,0.0003048]

print("Converted Length=",lst[ch-1]*len)