"""◮ Problem: given a tree, color nodes black as many as possible
without coloring two adjacent nodes
◮ Subproblems:
– First, we arbitrarily decide the root node r
– Bv: the optimal solution for a subtree having v as the root,
where we color v black
– Wv: the optimal solution for a subtree having v as the root,
where we don’t color v
– Answer is max{Br, Wr}
◮ Find the recurrence
– Crucial observation: once v’s color is determined, subtrees can
be solved independently
– If v is colored, its children must not be colored
Bv = 1 + X
u∈children(v)
Wu
– If v is not colored, its children can have any color
Wv = 1 + X
u∈children(v)
max{Bu, Wu}
◮ Base cases: leaf nodes


m Coloring Problem
"""
n = 4
B = [0 for i in range(n)]
W = [0 for i in range(n)]

B[3] = 2
for i in range(n):
    for j in range(n):
        B[i] = 1 + W[i-1]
        W[i] = 1 + max(B[i-1],W[i-1])
print(B,W)