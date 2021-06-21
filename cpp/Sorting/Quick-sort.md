## Quick sort
![Quciksort-visualization](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6a/Sorting_quicksort_anim.gif/220px-Sorting_quicksort_anim.gif)

- Divide and conquer algorithm
- works by selecting a pivot element and partitioning the other elements into two sub arrays,sub arrays are sorted recursive ly in place
- not stable(relative order not maintained)
- doesn't require extra space
- Time complexity
    -  **average case** = O(nlogn)
    - **Worst case** = O(n^2)
- pivot selection:
    -    mostly at last element 
    - **medians of median**:
    guarantees pivots nears middle of the data
- Variants:
    - Iterative Quick Sort:
