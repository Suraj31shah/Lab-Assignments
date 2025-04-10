import numpy as np
import matplotlib.pyplot as plt

# Define the polynomial function
def f(x):
    return x**3 - 4*x - 9  # Example polynomial

# Function to randomly find an initial interval [a, b] where f(a) * f(b) < 0
def find_initial_interval():
    while True:
        a, b = np.random.uniform(-10, 10, 2)  # Random values in range [-10, 10]
        if a > b:
            a, b = b, a  # Ensure a < b
        if f(a) * f(b) < 0:
            return a, b  # Valid interval found
0
# Bisection method implementation
def bisection_method(tol=1e-6, max_iter=100):
    a, b = find_initial_interval()
    midpoints = []  # Store all midpoints for plotting

    for _ in range(max_iter):
        c = (a + b) / 2
        midpoints.append(c)  # Store midpoint

        if abs(f(c)) < tol:  # Root found
            break
        elif f(a) * f(c) < 0:
            b = c  # Root is in [a, c]
        else:
            a = c  # Root is in [c, b]

    return np.array(midpoints)  # Return NumPy array of midpoints

# Run the Bisection method
midpoints = bisection_method()

# Plot the convergence of the root
plt.plot(midpoints, np.arange(len(midpoints)), 'o-', label="Bisection Steps")
plt.xlabel("Midpoint (Root Approximation)")
plt.ylabel("Iteration Step")
plt.title("Convergence of the Bisection Method")
plt.legend()
plt.grid()
plt.show()
