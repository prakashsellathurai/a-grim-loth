def bubblesort(arr):
    N = len(arr)
    for i in range(N):
        for j in range(N):
            if arr[j] > arr[i]:
                arr[j],arr[i] = arr[i],arr[j]
    return arr

if __name__ == "__main__":
    arr = [0,4,5,6,7,8,2,1,5,3,9]
    print(bubblesort(arr))