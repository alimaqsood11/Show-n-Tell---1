import random
import time
import matplotlib.pyplot as plt

def display_array(arr):
    print("Array:", " ".join(map(str, arr)))

def bubble_sort(arr, step_by_step=False):
    start = time.time()
    n = len(arr)
    comparisons, swaps = 0, 0
    for i in range(n - 1):
        for j in range(n - i - 1):
            comparisons += 1
            if arr[j] < arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swaps += 1
                if step_by_step:
                    display_array(arr)
    elapsed = (time.time() - start) * 1000  # ms
    return elapsed, comparisons, swaps

def insertion_sort(arr, step_by_step=False):
    start = time.time()
    comparisons, swaps = 0, 0
    for j in range(1, len(arr)):
        key = arr[j]
        i = j - 1
        while i >= 0 and arr[i] < key:
            comparisons += 1
            arr[i + 1] = arr[i]
            swaps += 1
            i -= 1
            if step_by_step:
                display_array(arr)
        arr[i + 1] = key
    elapsed = (time.time() - start) * 1000
    return elapsed, comparisons, swaps

def merge_sort(arr, step_by_step=False):
    comparisons, swaps = 0, 0

    def merge_sort_recursive(arr):
        nonlocal comparisons, swaps
        if len(arr) > 1:
            mid = len(arr) // 2
            left_half = arr[:mid]
            right_half = arr[mid:]

            merge_sort_recursive(left_half)
            merge_sort_recursive(right_half)

            i = j = k = 0
            while i < len(left_half) and j < len(right_half):
                comparisons += 1
                if left_half[i] > right_half[j]:
                    arr[k] = left_half[i]
                    i += 1
                else:
                    arr[k] = right_half[j]
                    j += 1
                swaps += 1
                k += 1
                if step_by_step:
                    display_array(arr)

            while i < len(left_half):
                arr[k] = left_half[i]
                i += 1
                k += 1

            while j < len(right_half):
                arr[k] = right_half[j]
                j += 1
                k += 1

    start = time.time()
    merge_sort_recursive(arr)
    elapsed = (time.time() - start) * 1000
    return elapsed, comparisons, swaps

def selection_sort(arr, step_by_step=False):
    start = time.time()
    comparisons, swaps = 0, 0
    n = len(arr)
    for i in range(n):
        max_idx = i
        for j in range(i + 1, n):
            comparisons += 1
            if arr[j] > arr[max_idx]:
                max_idx = j
        arr[i], arr[max_idx] = arr[max_idx], arr[i]
        swaps += 1
        if step_by_step:
            display_array(arr)
    elapsed = (time.time() - start) * 1000
    return elapsed, comparisons, swaps

def quick_sort(arr, step_by_step=False):
    comparisons, swaps = 0, 0

    def quick_sort_recursive(arr, low, high):
        nonlocal comparisons, swaps
        if low < high:
            pi, comps, swps = partition(arr, low, high)
            comparisons += comps
            swaps += swps
            quick_sort_recursive(arr, low, pi - 1)
            quick_sort_recursive(arr, pi + 1, high)

    def partition(arr, low, high):
        pivot = arr[high]  # Standard pivot (last element)
        i = low - 1
        comps, swps = 0, 0
        for j in range(low, high):
            comps += 1
            if arr[j] <= pivot:  # Change comparison direction if needed
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
                swps += 1
                if step_by_step:
                    display_array(arr)
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        swps += 1
        return i + 1, comps, swps

    start = time.time()
    quick_sort_recursive(arr, 0, len(arr) - 1)
    elapsed = (time.time() - start) * 1000
    return elapsed, comparisons, swaps


algorithms = {
    "Bubble Sort": bubble_sort,
    "Insertion Sort": insertion_sort,
    "Merge Sort": merge_sort,
    "Selection Sort": selection_sort,
    "Quick Sort": quick_sort
}

def compare_sorting_algorithms(arr):
    results = {}
    for name, func in algorithms.items():
        arr_copy = arr.copy()
        time_taken, comparisons, swaps = func(arr_copy)
        results[name] = {"Time (ms)": time_taken, "Comparisons": comparisons, "Swaps": swaps}

    print("\n[ Sorting Algorithms Comparison ]")
    print(f"{'Algorithm':<15}{'Time (ms)':<12}{'Comparisons':<12}{'Swaps':<8}")
    print("-" * 50)
    for name, data in results.items():
        print(f"{name:<15}{data['Time (ms)']:<12.2f}{data['Comparisons']:<12}{data['Swaps']:<8}")

    plt.figure(figsize=(10, 6))
    algorithm_names = list(results.keys())
    times = [results[name]["Time (ms)"] for name in algorithm_names]

    plt.bar(algorithm_names, times, color=['blue', 'green', 'purple', 'orange', 'red'])
    plt.title("Sorting Algorithm Performance")
    plt.xlabel("Algorithm")
    plt.ylabel("Time (ms)")
    plt.show()


def batch_sorting_comparison():
    sizes = [100, 500, 1000, 5000, 10000]
    results = {alg: [] for alg in algorithms}

    print("\n[ Batch Sorting Comparison ]")
    print(f"Running sorting algorithms on arrays of sizes: {sizes}")

    for size in sizes:
        arr = [random.randint(1, 10000) for _ in range(size)]
        print(f"\nTesting array of size {size}...")
        
        for name, func in algorithms.items():
            print(f"Running {name}...")
            time_taken, comparisons, swaps = func(arr.copy())
            results[name].append({"Time (ms)": time_taken, "Comparisons": comparisons, "Swaps": swaps})

    print("\n[ Sorting Algorithms Batch Comparison Results ]")
    print(f"{'Algorithm':<15}{'100':<12}{'500':<12}{'1000':<12}{'5000':<12}{'10000':<12}")
    print("-" * 70)
    for name in results:
        print(f"{name:<15}", end="")
        for res in results[name]:
            print(f"{res['Time (ms)']:<12.2f}", end="")
        print()

    plt.figure(figsize=(10, 6))
    for name, result_list in results.items():
        times = [res['Time (ms)'] for res in result_list]
        plt.plot(sizes, times, label=name)

    plt.title("Sorting Algorithm Performance Comparison (Batch Test)")
    plt.xlabel("Array Size")
    plt.ylabel("Time (ms)")
    plt.legend()
    plt.show()


def main():
    print("Welcome to the Enhanced Sorting Algorithm Analysis Tool!\n")
    while True:
        print("\nChoose an option:")
        print("[A] Sorting Algorithms Time Analysis")
        print("[B] Compare All Sorting Algorithms")
        print("[C] Batch Sorting and Result Comparison")
        print("[D] Exit")
        choice = input("Enter your choice: ").strip().lower()

        if choice == 'a':
            n = int(input("Enter the number of elements to sort: "))
            array_type = input("Choose array type - [1] Random, [2] Ascending: ").strip()
            if array_type == '1':
                arr = [random.randint(1, 10000) for _ in range(n)]
            elif array_type == '2':
                arr = list(range(1, n + 1))
            else:
                print("Invalid input. Generating random array by default.")
                arr = [random.randint(1, 10000) for _ in range(n)]
            
            print(f"Array generated with {n} elements.")
            print("Choose a sorting algorithm:")
            for i, alg in enumerate(algorithms, start=1):
                print(f"[{i}] {alg}")
            choice1 = int(input("Enter your choice number: ").strip())

            selected_algorithm = list(algorithms.values())[choice1 - 1]
            step_by_step = input("Show steps? (y/n): ").strip().lower() == 'y'
            elapsed, comparisons, swaps = selected_algorithm(arr.copy(), step_by_step=step_by_step)
            print(f"Time taken: {elapsed:.2f} ms, Comparisons: {comparisons}, Swaps: {swaps}")
        
        elif choice == 'b':
            n = int(input("Enter the number of elements to sort: "))
            arr = [random.randint(1, 10000) for _ in range(n)]
            compare_sorting_algorithms(arr)
        
        elif choice == 'c':
            batch_sorting_comparison()
        
        elif choice == 'd':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
