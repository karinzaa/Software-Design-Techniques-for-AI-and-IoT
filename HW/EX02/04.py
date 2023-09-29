import sys

def merge(array, left, mid, right):
    temp = []
    i = left
    j = mid + 1
    while i <= mid and j <= right:
        if array[i] < array[j]:
            temp.append(array[i])
            i += 1
        else:
            temp.append(array[j])
            j += 1
    while i <= mid:
        temp.append(array[i])
        i += 1
    while j <= right:
        temp.append(array[j])
        j += 1
    for i in range(left, right + 1):
        array[i] = temp[i - left]


def merge_unequal_subarrays(array, left, mid, right):
    temp = []
    i = left
    j = mid + 1
    while i <= mid and j <= right:
        if array[i] < array[j]:
            temp.append(array[i])
            i += 1
        else:
            temp.append(array[j])
            j += 1
    while i <= mid:
        temp.append(array[i])
        i += 1
    while j <= right:
        temp.append(array[j])
        j += 1
    for i in range(left, right + 1):
        array[i] = temp[i - left]

def merge_sort(array, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(array, left, mid)
        merge_sort(array, mid + 1, right)
        if (right - left + 1) % 2 != 0:
            merge_unequal_subarrays(array, left, mid, right)
        else:
            merge(array, left, mid, right)

def main():
    array = list(map(int, sys.argv[1:]))
    merge_sort(array, 0, len(array) - 1)
    print(array)

if __name__ == '__main__':
    main()
