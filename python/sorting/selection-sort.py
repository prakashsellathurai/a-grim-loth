def selectionsort(arr,N):
    
    for i in range(N):
        minimum = i
        for j in range(1,N):
            if arr[j] < arr[minimum]:
                minimum = j
        arr[minimum],arr[i] = arr[i],arr[minimum]
    return arr

if __name__ == "__main__":
    arr = [0,4,5,6,7,8,2,1,5,3,9]
    print(selectionsort(arr,len(arr)))