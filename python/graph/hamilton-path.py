""" O(n*logn) implementation """

from random import randint
from functools import cmp_to_key
from time import perf_counter

if __name__ == "__main__":
    print("Takes some time to benchmark ......")

    cap = 12
    size = 2 ** cap

    graph = [
        [1 for i in range(size)] for k in range(size)
    ]  # Adjacency matrix representation

    for i in range(size):  # Building 1 big tournament
        for j in range(i, size):
            if randint(0, 1) or j == i:  # Setting directions and removing loops
                graph[i][j] = 0  # Removing i -> j
            else:
                graph[j][i] = 0  # Removing j -> i

    for i in range(size):  # Tournament correctness check
        for j in range(size):
            if i != j:
                if graph[i][j] == graph[j][i]:
                    raise AssertionError
            else:
                if graph[i][j] != 0:
                    raise AssertionError

    for z in range(2, cap + 1):  # Finding Hamiltonian paths for subgraphs
        subgraph_size = 2 ** z
        start_time = perf_counter()
        hamiltonian_path = sorted(
            range(subgraph_size), key=cmp_to_key(lambda a, b: graph[b][a] - graph[a][b])
        )
        # print(hamiltonian_path, end='\n\n')  # Output path
        print(
            "Time: {:f}s | Size: {:d}".format(
                perf_counter() - start_time, subgraph_size
            )
        )

        for i in range(subgraph_size - 1):  # Hamiltonian path check
            if not graph[hamiltonian_path[i]][
                hamiltonian_path[i + 1]
            ]:
                raise AssertionError

    print("")  # New line between cases
