from bisect import bisect_left as lower_bound
def build_tree(tree,arr,idx,l,r):
    if l==r:
        tree[idx].append(arr[l])
    else:
        mid=(l+r)//2
        build_tree(tree,arr,2*idx+1,l,mid)
        build_tree(tree,arr,2*idx+2,mid+1,r)
        tree[idx]=merge(tree[2*idx+1],tree[2*idx+2])


def merge(left,right):
    myList=[]
    i=0
    j=0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:

            myList.append(left[i])

            i += 1
        else:
            myList.append(right[j])
            j += 1



    while i < len(left):
        myList.append(left[i])
        i += 1


    while j < len(right):
        myList.append(right[j])
        j += 1

    return myList
def query(Tree,index,s,e,l,r,k):
    if r<s or l>e:
        return 0 
    if s >= l and e <=r:
        return len(Tree[index]) - lower_bound(Tree[index],k)
    mid = (s+e) //2
    return query(Tree,2*index+1,s,mid,l,r,k) + query(Tree,2*index+2,mid+1,e,l,r,k)

if __name__ == '__main__':
    n=4
    arr=[1,2,3,4]
    tree=[[] for i in range(2*n-1)]
    build_tree(tree,arr,0,0,n-1)
    print(tree)
    for i in range(n):
        print(query(tree,1,0,n-1,i,n-1,arr[i]))