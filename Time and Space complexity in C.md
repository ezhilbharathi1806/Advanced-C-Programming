### ✅ **Time Complexity**:
* how the execution time of a program or algorithm increases with the size of the input. expressed using **Big O notation**
* Time complexity helps estimate how fast the program runs.
	1. O(1): Constant time. The running time doesn’t change with the input size. Example: Accessing an array element by index.
	2. O(log n): Logarithmic time. The running time increases logarithmically as the input size increases. Example: Binary search in a sorted array.
	3. O(n): Linear time. The running time increases linearly with the input size. Example: Iterating through an array.
	4. O(n log n): Log-linear time. Common in efficient sorting algorithms like mergesort and quicksort.
	5. O(n²): Quadratic time. The running time grows quadratically with the input size. Example: Nested loops, such as in bubble sort.
	6. O(2^n): Exponential time. The running time doubles with each additional input element. Example: Recursive algorithms solving the Towers of Hanoi.
	7. O(n!): Factorial time. The running time grows factorially with the input size. Example: Brute-force solutions to the traveling salesman problem.
### ✅ **Space Complexity**:
* how much extra memory (RAM) the algorithm uses relative to input size.  expressed in Big O notation.
* It includes **input storage, auxiliary space (like arrays, variables, stacks, etc.)**, and function call stack memory.
	1. O(1): Constant space. The algorithm uses a fixed amount of memory regardless of input size. Example: Variables storing sums or counters.
	2. O(n): Linear space. The memory usage grows linearly with the input size. Example: Storing an additional array or list.
	3. O(n²): Quadratic space. The memory usage grows quadratically with the input size. Example: Storing a 2D matrix.

---

## Common Time Complexities

| Notation   | Name              | Example                    |
| ---------- | ----------------- | -------------------------- |
| O(1)       | Constant time     | Accessing an array element |
| O(n)       | Linear time       | Loop through array         |
| O(n²)      | Quadratic time    | Nested loops               |
| O(log n)   | Logarithmic time  | Binary search              |
| O(n log n) | Linearithmic time | Merge sort                 |

---

 C Programming Example - **sum of elements in an array**

```c
#include <stdio.h>

int sum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = sum(arr, n);
    printf("Sum = %d\n", result);
    return 0;
}
```

---

###  Time Complexity Analysis:

* The loop runs from `i = 0` to `i = n-1`, i.e., **n times**.
* Each operation inside the loop (`total += arr[i]`) takes **constant time** → `O(1)`.
* So total time = **n × O(1) = O(n)**

 **Time Complexity: O(n)**

---

### Space Complexity Analysis:

* Input array `arr[]`: uses `O(n)` space.
* Variable `total` and `i` use `O(1)` space.
* No extra data structures used.

 **Auxiliary Space Complexity: O(1)** (input not counted unless stated)
**Total Space Complexity: O(n)** (if input array is considered)

---

Another Example: Bubble Sort in C

```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

* **Time Complexity:**

  * Outer loop runs `n-1` times.
  * Inner loop runs up to `n-i-1` times.
  * In worst case, total operations = `n(n-1)/2` → **O(n²)**

* **Space Complexity:**

  * Only a few extra variables: `i`, `j`, `temp` → **O(1)** auxiliary space

**Time: O(n²)**, **Space: O(1)**

---

## 📌 Summary Table

| Algorithm     | Time Complexity | Space Complexity |
| ------------- | --------------- | ---------------- |
| Array Sum     | O(n)            | O(1) auxiliary   |
| Bubble Sort   | O(n²)           | O(1)             |
| Binary Search | O(log n)        | O(1)             |
| Merge Sort    | O(n log n)      | O(n)             |


