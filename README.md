
🔁 Bubble Sort
Bubble Sort repeatedly compares and swaps adjacent elements if they are in the wrong order. During each pass, the largest unsorted element "bubbles up" to its correct position at the end of the array. This process is repeated for all elements until the entire array is sorted. It’s simple but inefficient for large data due to its high time complexity. The best case is when the array is already sorted (O(n)), and the worst is O(n²). It is a stable sort and works in-place without extra memory.

✅ Selection Sort
Selection Sort divides the array into a sorted and an unsorted part. In each iteration, it selects the smallest (or largest) element from the unsorted part and swaps it with the first unsorted element. This process is repeated, expanding the sorted section one element at a time. It performs the same number of comparisons regardless of the input order (O(n²)). It is an in-place sorting algorithm but not stable by default. It’s more efficient than bubble sort in terms of swaps, but not in comparisons.

🔀 Merge Sort
Merge Sort is a divide-and-conquer algorithm that recursively divides the array into halves until each subarray has one element. Then, it merges the subarrays in sorted order. This merging process ensures that the final result is a sorted array. Merge Sort has a consistent time complexity of O(n log n) in all cases. It is stable and suitable for sorting large datasets, though it uses extra memory for merging. It is not an in-place sort because of its auxiliary arrays.

⚡ Quick Sort
Quick Sort is also a divide-and-conquer algorithm that selects a pivot element and partitions the array around it—smaller elements go left, larger ones go right. It then recursively applies the same process to the left and right subarrays. Its average-case time complexity is O(n log n), but the worst case is O(n²) (e.g., when the pivot is the smallest/largest). It is efficient for large datasets and generally faster than merge sort due to lower overhead. Quick Sort is in-place but not stable by default.

🧠 Visual Example of Sorting Process
Let’s say we want to sort:
Array: [34, 10, 25, 5]

🫧 Bubble Sort Steps:
[10, 25, 5, 34] → biggest bubbles to end

[10, 5, 25, 34]

[5, 10, 25, 34] → done

✅ Selection Sort Steps:
Find min (5), swap with 34 → [5, 10, 25, 34]

Find next min (10) → no swap

Find next min (25) → no swap

Done

🔀 Merge Sort Steps:
Split → [34, 10] and [25, 5]

Merge each → [10, 34], [5, 25]

Merge both → [5, 10, 25, 34]

⚡ Quick Sort Steps:
Choose pivot (say 34)

Partition → [10, 25, 5] | 34

Recursively sort [10, 25, 5]

Final → [5, 10, 25, 34]
