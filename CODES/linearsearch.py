def linear_search(arr, i, j, x):
    if arr[i] == x:
        return i
    elif i == j:
        return -1
    else:
        return linear_search(arr, i + 1, j, x)

arr = list(map(int, input("Enter the elements of the array (space-separated): ").split()))
x = int(input("Enter the value to search for: "))
result = linear_search(arr, 0, len(arr) - 1, x)

if result != -1:
    print(f"Element {x} found at index {result}.")
else:
    print(f"Element {x} not found in the array.")
