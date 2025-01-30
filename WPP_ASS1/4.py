nums=list(range(1,100))

equivalence_classes={0:[], 1:[], 2:[], 3:[], 4:[]}

for num in nums:
    rem=num%5
    equivalence_classes[rem].append(num)

union_of_classes=[]

for eq_class in equivalence_classes.values():
    union_of_classes.extend(eq_class)

union_of_classes=sorted(union_of_classes)

is_valid=(union_of_classes==nums)

print("Equivalence classes (modulo 5):")
for rem,eq_class in equivalence_classes.items():
    print(f"Class {rem}: {eq_class[:10]}...")

print("\nValidity of equivalence classes:",is_valid)