# Returns count of all possible
# parenthesizations that lead to
# result true for a boolean
# expression with symbols like
# true and false and operators
# like &, | and ^ filled between symbols


def countParenth(symb, oper, n):
    F = [[0 for i in range(n + 1)] for i in range(n + 1)]
    T = [[0 for i in range(n + 1)] for i in range(n + 1)]

    # Fill diaginal entries first
    # All diagonal entries in
    # T[i][i] are 1 if symbol[i]
    # is T (true). Similarly, all
    # F[i][i] entries are 1 if
    # symbol[i] is F (False)
    for i in range(n):
        if symb[i] == "F":
            F[i][i] = 1
        else:
            F[i][i] = 0

        if symb[i] == "T":
            T[i][i] = 1
        else:
            T[i][i] = 0

    # Now fill T[i][i+1], T[i][i+2],
    # T[i][i+3]... in order And
    # F[i][i+1], F[i][i+2],
    # F[i][i+3]... in order
    for gap in range(1, n):
        i = 0
        for j in range(gap, n):
            T[i][j] = F[i][j] = 0
            for g in range(gap):

                # Find place of parenthesization
                # using current value of gap
                k = i + g

                # Store Total[i][k] and Total[k+1][j]
                tik = T[i][k] + F[i][k]
                tkj = T[k + 1][j] + F[k + 1][j]

                # Follow the recursive formulas
                # according to the current operator
                if oper[k] == "&":
                    T[i][j] += T[i][k] * T[k + 1][j]
                    F[i][j] += tik * tkj - T[i][k] * T[k + 1][j]
                if oper[k] == "|":
                    F[i][j] += F[i][k] * F[k + 1][j]
                    T[i][j] += tik * tkj - F[i][k] * F[k + 1][j]
                if oper[k] == "^":
                    T[i][j] += F[i][k] * T[k + 1][j] + T[i][k] * F[k + 1][j]
                    F[i][j] += T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j]
            i += 1
    return T[0][n - 1]


# Driver Code
symbols = "TTFT"
operators = "|&^"
n = len(symbols)

# There are 4 ways
# ((T|T)&(F^T)), (T|(T&(F^T))),
# (((T|T)&F)^T) and (T|((T&F)^T))
print(countParenth(symbols, operators, n))
