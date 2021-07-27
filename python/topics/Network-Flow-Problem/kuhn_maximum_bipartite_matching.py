def try_kuhn(v, g, mt, used):
    if used[v]:
        return False
    used[v] = True

    for i, to in enumerate(g[v]):
        if mt[i] == -1 or try_kuhn(mt[i], g, mt, used):
            mt[i] = v
            return True
    return False


if __name__ == "__main__":
    g = [[4, 15, 20], [7, 10, 19], [7, 20, 4]]
    n = len(g)
    k = len(g[0])
    mt = [-1] * n
    used = [False] * n

    for v in range(n):
        uused = [False] * n
        try_kuhn(v, g, mt, used)

    total_cost = 0
    for i in range(n):
        if mt[i] != -1:
            total_cost += g[mt[i]][i]
            print("%d %d\n", mt[i], i)
    print(("lowest cost=%s" % total_cost))
