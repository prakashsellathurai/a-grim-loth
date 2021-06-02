from collections import Counter


MAX_N = int(1e5 + 14)
def solution(a,n):
    mark = [False] * MAX_N
    mex = 0
    pre = []
    for x in a:
        mark[x] = True
        while mark[mex]:
            mex += 1
        pre += [mex]
    mark = [False] * MAX_N
    mex = 0
    ans = -1
    for i in range(n - 1, 0, -1):
        mark[a[i]] = True
        while mark[mex]:
            mex += 1
        if mex == pre[i - 1]:
            ans = i
    return(ans)

    # return -1
print(solution([0 ,2 ,2 ,3 ,0],5))