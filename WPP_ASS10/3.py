import numpy as np

def generate_magic_square(n):
    """Generates an N x N magic square."""
    if n % 2 == 1:
        return odd_order_magic_square(n)
    elif n % 4 == 0:
        return doubly_even_magic_square(n)
    else:
        return singly_even_magic_square(n)

def odd_order_magic_square(n):
    """Generates a magic square for odd N using the Siamese method."""
    magic_square = np.zeros((n, n), dtype=int)
    i, j = 0, n // 2
    for num in range(1, n * n + 1):
        magic_square[i, j] = num
        i_new, j_new = (i - 1) % n, (j + 1) % n
        if magic_square[i_new, j_new]:
            i += 1
        else:
            i, j = i_new, j_new
    return magic_square

def doubly_even_magic_square(n):
    """Generates a magic square for doubly even order (N % 4 == 0)."""
    magic_square = np.arange(1, n * n + 1).reshape(n, n)
    mask = np.zeros((n, n), dtype=bool)
    for i in range(n):
        for j in range(n):
            if (i % 4 == j % 4) or (i % 4 + j % 4 == 3):
                mask[i, j] = True
    magic_square[mask] = n * n + 1 - magic_square[mask]
    return magic_square

def singly_even_magic_square(n):
    """Generates a magic square for singly even order (N % 2 == 0 but not 4)."""
    half_n = n // 2
    sub_square = odd_order_magic_square(half_n)
    magic_square = np.zeros((n, n), dtype=int)
    
    for i in range(2):
        for j in range(2):
            magic_square[i * half_n:(i + 1) * half_n, j * half_n:(j + 1) * half_n] = sub_square + (i * 2 + j) * (half_n ** 2)
    
    k = half_n // 2
    cols = list(range(k)) + list(range(n - k + 1, n))
    magic_square[:half_n, cols], magic_square[half_n:, cols] = magic_square[half_n:, cols], magic_square[:half_n, cols]
    magic_square[k, 0], magic_square[k + half_n, 0] = magic_square[k + half_n, 0], magic_square[k, 0]
    magic_square[k, k], magic_square[k + half_n, k] = magic_square[k + half_n, k], magic_square[k, k]
    return magic_square

def main():
    for n in [4, 5, 6, 7, 8]:
        print(f"Magic Square for N={n}:")
        print(generate_magic_square(n))
        print()

if __name__ == "__main__":
    main()
