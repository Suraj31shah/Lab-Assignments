def next_permutation(w):
    w = list(w)
    n = len(w)
    
    i = n - 2
    while i >= 0 and w[i] >= w[i + 1]:
        i -= 1
    
    if i == -1:
        return "no answer"
    
    j = n - 1
    while w[j] <= w[i]:
        j -= 1
    
    w[i], w[j] = w[j], w[i]
    
    w = w[:i+1] + sorted(w[i+1:])
    
    return "".join(w)

t = int(input().strip())
for _ in range(t):
    w = input().strip()
    print(next_permutation(w))
