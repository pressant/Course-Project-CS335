# Quicksort Algorithm Implementation

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quicksort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quicksort(arr, low, pi - 1)
        quicksort(arr, pi + 1, high)

# Mergesort Algorithm Implementation

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m

    L = [arr[l + i] for i in range(n1)]
    R = [arr[m + 1 + j] for j in range(n2)]

    i = j = 0
    k = l

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def mergesort(arr, l, r):
    if l < r:
        m = (l + r) // 2
        mergesort(arr, l, m)
        mergesort(arr, m + 1, r)
        merge(arr, l, m, r)

def main():
    arr = [10, 7, 8, 9, 1, 5]
    n = len(arr)

    # Quicksort
    print("Original array (Quicksort):", arr)
    quicksort(arr, 0, n - 1)
    print("Sorted array (Quicksort):", arr)

    # Mergesort
    arr = [10, 7, 8, 9, 1, 5]  # Restore original array
    print("\nOriginal array (Mergesort):", arr)
    mergesort(arr, 0, n - 1)
    print("Sorted array (Mergesort):", arr)

if __name__ == "__main__":
    main()

