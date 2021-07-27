import time

count = []


def fib(n):
    count.append(n)
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)


def estimate(f):
    start = time.time_ns()
    f
    print(time.time_ns() - start)


n = 10
fib(n)
print(len(count))
memo = {0: 1, 1: 1}
count = []
numCalls = 0


def fastFib(n):
    global numCalls
    numCalls += 1
    if not n in memo:
        memo[n] = fastFib(n - 1) + fastFib(n - 2)
    return memo[n]


fastFib(n)
print(numCalls)
