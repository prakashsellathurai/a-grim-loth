def Insertionsort(arr, N):
    for i in range(N):
        temp = arr[i]
        j = i
        while j > 0 and temp < arr[j - 1]:
            arr[j] = arr[j - 1]
            j = j - 1
        arr[j] = temp
    return arr


if __name__ == "__main__":
    arr = [0, 4, 5, 6, 7, 8, 2, 1, 5, 3, 9]
    print(Insertionsort(arr, len(arr)))
