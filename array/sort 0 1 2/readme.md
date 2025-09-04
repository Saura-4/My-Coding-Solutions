# 💡 Problem: Sort Colors
[Link](https://leetcode.com/problems/sort-colors/)
<br>
**Tags:** `#array`, `#two-pointers`, `#sorting`, `#in-place`

---

## The "Aha!" Moment / Core Idea
The key is to solve this in a **single pass** with $O(1)$ extra space using the **Dutch National Flag algorithm**. This algorithm uses three pointers (`low`, `mid`, `high`) to partition the array into three sections in place: a section for 0s at the beginning, 1s in the middle, and 2s at the end.



---

## Approach & Data Structures
**Algorithm:** Dutch National Flag algorithm.
<br>
**Main Data Structure:** Three integer pointers are used:
* `low`: Marks the end of the 0's section.
* `mid`: The current element being processed.
* `high`: Marks the beginning of the 2's section.

**Logic:** The `mid` pointer iterates through the array. Based on its value, elements are swapped into the `low` or `high` sections, and the pointers are adjusted accordingly. The loop continues as long as `mid <= high`.

---

## How It Works
The three pointers manage three distinct partitions of the array. The algorithm's goal is to shrink the "unknown" section (between `mid` and `high`) by correctly placing the element at `nums[mid]`.

1.  **If `nums[mid]` is 0**
    ```cpp
    if (nums[mid] == 0) {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
    }
    ```
    **Logic:** A `0` belongs at the beginning of the array. We swap it with the element at the `low` pointer and then advance both `low` and `mid`.
    <br>
    **Why:** We advance `low` because we've successfully expanded the 0's section. We can also safely advance `mid` because the element we just swapped into `nums[mid]` (from the `low` position) is guaranteed to have already been processed and must be a `1`.

2.  **If `nums[mid]` is 2**
    ```cpp
    else if (nums[mid] == 2) {
        swap(nums[mid], nums[high]);
        high--;
    }
    ```
    **Logic:** A `2` belongs at the end. We swap it with the element at the `high` pointer and then shrink the 2's section by decrementing `high`.
    <br>
    **Why:** We **do not advance `mid`**. The new element that has been swapped into `nums[mid]` is an unknown value from the end of the array. It must be processed in the next iteration of the loop.

3.  **If `nums[mid]` is 1**
    ```cpp
    else { // nums[mid] == 1
        mid++;
    }
    ```
    **Logic:** A `1` is already in its correct potential partition (the middle). We don't need to move it.
    <br>
    **Why:** We simply advance the `mid` pointer to move on to the next unknown element.

---

## Complexity Analysis
* **Time Complexity:** $O(N)$ - The `mid` pointer makes a single pass through the array.
* **Space Complexity:** $O(1)$ - The sorting is done **in-place** without using any extra space proportional to the input size.
