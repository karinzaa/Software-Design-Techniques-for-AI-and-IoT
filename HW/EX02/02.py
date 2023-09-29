import sys
import random

def partition(arr, low, high):
    pivot_index = random.randint(low, high)
    arr[high], arr[pivot_index] = arr[pivot_index], arr[high]
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quickselect(arr, low, high, k):
    if low <= high:
        pi = partition(arr, low, high)
        if pi == k:
            return arr[pi]
        elif pi < k:
            return quickselect(arr, pi + 1, high, k)
        else:
            return quickselect(arr, low, pi - 1, k)
    return None

def find_median(arr):
    n = len(arr)
    if n % 2 == 1:
        k = n // 2
        return quickselect(arr, 0, n - 1, k)
    else:
        k1 = n // 2 - 1
        k2 = n // 2
        val1 = quickselect(arr, 0, n - 1, k1)
        val2 = quickselect(arr, 0, n - 1, k2)
        return (val1 + val2) / 2

if __name__ == "__main__":
    numbers = [int(arg) for arg in sys.argv[1:]]
    if numbers:
        median = find_median(numbers)
        print(f"The median is: {median}")
    else:
        print("Please provide numbers as command line arguments.")