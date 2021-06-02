from bisect import bisect_left,bisect_right

def Merge(left,right):
    mergedList = []
    i = j = 0
    
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            mergedList.append(left[i])
            i+=1
        else:
            mergedList.append(right[j])
            j+=1
    while i < len(left):
        mergedList.append(left[i])
        i+=1
    while j < len(right):
        mergedList.append(right[j])
        j+=1
    
    return mergedList
def BuildMergeSortTree(Tree,A,index,start,end):
    if start == end:
        Tree[index].append(A[start])
        return
    else:
        mid = (start+end) // 2
        BuildMergeSortTree(Tree,A,2*index,start,mid)
        BuildMergeSortTree(Tree,A,2*index+1,mid+1,end)
        Tree[index] = Merge(Tree[2*index],Tree[2*index+1])
def query(Tree,index,start,end,left,right,k):
    if right < start or left > end :
        return 0
    if start >= left and end <= right:
        # binary search to find index of k
        print(Tree[index])
        try:
            start_ele = Tree[index][0]
        except:
            start_ele = 0
        return len(Tree[index]) - (bisect_left(Tree[index], k)) - start_ele
    mid = (start+end) //2
    return query(Tree,2*index,start,mid,left,right,k)+query(Tree,2*index+1,mid+1,end,left,right,k)
     
def solve(A,B,N):
    Tree = [[] for i in range(4*N+1)]
    BuildMergeSortTree(Tree,A,0,0,N-1)
    for i in range(N):
        value = A[i]
        start = i
        end = N-1
        ans = -1
        while start <= end:
            m = (start + end) >> 1
            cnt = query(Tree,1,0,N-1,i,m,value)
            if cnt >= B[i]:
                ans = m
                end = m-1
            else:
                start = m+1
        if ans == -1:
            print(-1,end = ' ')
        else:
            print(ans-i+1,end = ' ') 
        
N = 5
A = list(map(int,'8 2 4 1 9'.split()))
B = list(map(int,'2 3 5 1 1'.split()))     
solve(A,B,N)