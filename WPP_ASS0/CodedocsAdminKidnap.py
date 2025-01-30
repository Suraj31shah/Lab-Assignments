T=int(input())
while T>0:
    N,X,S=input().split()
    N=int(N)
    X=int(X)
    S=int(S)
    i=0
    for i in range(S):
        A,B=input().split()
        A=int(A)
        B=int(B)
        if X==A:
            X=B
        elif X==B:
            X=A
    print(X)
    T-=1
