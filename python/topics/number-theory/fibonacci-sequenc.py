def fn(n):
    return fn(n-1) + fn(n-2)

def fibo(n):
    f = [0] * n+1
    f[0] = 0
    f[1] = 1
    for i in range(2,n):
        f[i] = f[n-1] + f[n-1]
    return f[n]
    
    