import numpy as np

# Sample NumPy array
arr = np.array(["apple", "banana", "cherry", "date", "elderberry"])

# Function to format the strings manually
def format_strings(arr):
    formatted_centered = np.array(["_" * ((15 - len(s)) // 2) + s + "_" * ((15 - len(s) + 1) // 2) for s in arr])
    formatted_left = np.array([s + "_" * (15 - len(s)) for s in arr])
    formatted_right = np.array(["_" * (15 - len(s)) + s for s in arr])

    return formatted_centered, formatted_left, formatted_right

# Apply formatting
centered, left_justified, right_justified = format_strings(arr)

# Print results
print("Original Array:")
print(arr)

print("\nCentered:")
print(centered)

print("\nLeft-Justified:")
print(left_justified)

print("\nRight-Justified:")
print(right_justified)
