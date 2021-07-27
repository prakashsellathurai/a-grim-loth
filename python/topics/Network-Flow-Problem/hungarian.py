# ---------------------------------------------------------------------------
# Imports
# ---------------------------------------------------------------------------

import sys
import copy
from typing import Union, NewType, Sequence, Tuple, Optional, Callable
# ---------------------------------------------------------------------------
# Exports
# ---------------------------------------------------------------------------

__all__ = ['Munkres', 'make_cost_matrix', 'DISALLOWED']

# ---------------------------------------------------------------------------
# Globals
# ---------------------------------------------------------------------------

AnyNum = NewType('AnyNum', Union[int, float])
Matrix = NewType('Matrix', Sequence[Sequence[AnyNum]])

# Constants


class DISALLOWED_OBJ(object):
    pass


DISALLOWED = DISALLOWED_OBJ()
DISALLOWED_PRINTVAL = "D"

# ---------------------------------------------------------------------------
# Exceptions
# ---------------------------------------------------------------------------


class UnsolvableMatrix(Exception):
    """
    Exception raised for unsolvable matrices
    """
    pass


class Hungaraian():
    def __init__(self):
        """Create a new instance"""
        self.C = None
        self.row_covered = []
        self.col_covered = []
        self.n = 0
        self.Z0_r = 0
        self.Z0_c = 0
        self.marked = None
        self.path = None

    def pad_matrix(self, matrix: Matrix, pad_value: int = 0) -> Matrix:
        maxColumns = 0
        total_rows = len(matrix)

        for row in matrix:
            maxColumns = max(maxColumns, len(row))
        total_rows = max(maxColumns, total_rows)

        new_matrix = []

        for row in matrix:
            row_len = len(row)
            new_row = row[:]
            if total_rows > row_len:
                new_row += [pad_value] * (total_rows - row_len)
            new_matrix += [new_row]
        while len(new_matrix) < total_rows:
            new_matrix += [[pad_value]*total_rows]
        return new_matrix

    def compute(self, cost_matrix: Matrix) -> Sequence[Tuple[int, int]]:
        self.C = self.pad_matrix(cost_matrix)
        self.n = len(self.C)
        self.original_length = len(cost_matrix)
        self.original_width = len(cost_matrix[0])

        self.row_covered = [False for _ in range(self.n)]
        self.col_covered = [False for _ in range(self.n)]
        self.Z0_r = 0
        self.Z0_c = 0
        self.path = self.__make_matrix(self.n * 2, 0)
        self.marked = self.__make_matrix(self.n, 0)

        done = False
        step = 1

        steps = {1: self.__step1,
                 2: self.__step2,
                 3: self.__step3,
                 4: self.__step4,
                 5: self.__step5,
                 6: self.__step6}

        while not done:
            try:
                func = steps[step]
                step = func()
            except KeyError:
                done = True

    def __copy_matrix(self, matrix: Matrix) -> Matrix:
        """Return an exact copy of the supplied matrix"""
        return copy.deepcopy(matrix)

    def __make_matrix(self, n: int, val: AnyNum) -> Matrix:
        """Create an *n*x*n* matrix, populating it with the specific value."""
        matrix = []
        for _ in range(n):
            matrix += [[val for _ in range(n)]]
        return matrix

    def __clear_covers(self) -> None:
        """Clear all covered matrix cells"""
        for i in range(self.n):
            self.row_covered[i] = False
            self.col_covered[i] = False

    def __step1(self) -> int:
        C = self.C
        n = self.n
        for i in range(n):
            vals = [x for x in self.C[i] if x is not DISALLOWED]
            if len(vals) == 0:
                # All values in this row are DISALLOWED. This matrix is
                # unsolvable.
                raise UnsolvableMatrix(
                    "Row {0} is entirely DISALLOWED.".format(i)
                )
            minval = min(vals)
            # Find the minimum value for this row and subtract that minimum
            # from every element in the row.
            for j in range(n):
                if self.C[i][j] is not DISALLOWED:
                    self.C[i][j] -= minval
        return 2

    def __step2(self) -> int:
        n = self.n
        for i in range(n):
            for j in range(n):
                if self.C[i][j] == 0 and (not self.col_covered[j]) and (not self.row_covered[i]):
                    self.marked[i][j] = 1
                    self.col_covered[j] = self.row_covered[i] = True
                    break
        self.__clear_covers()
        return 3

    def __step3(self) -> int:
        n = self.n
        count = 0
        for i in range(n):
            for j in range(n):
                if self.marked[i][j] == 1 and not self.col_covered[j]:
                    self.col_covered[j] = True
                    count += 1
        if count >= n:
            step = 7
        else:
            step = 4
        return step

    def __step4(self) -> int:
        step = 0
        done = False
        row = col = 0
        star_col = -1
        while not done:
            (row, col) = self.__find_a_zero(row, col)
        return step

    def __step5(self) -> int:
    def __step6(self) -> int:


n = 3
A = [[4, 15, 20], [7, 10, 19], [7, 20, 4]]
m = Hungaraian()
indexes = m.compute(A)
total_cost = 0
for r, c in indexes:
    x = A[r][c]
    total_cost += x
    print(('(%d, %d) -> %s' % (r, c, x)))
print(('lowest cost=%s' % total_cost))
