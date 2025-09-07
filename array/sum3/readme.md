# 💡 Problem: 3Sum
[Link](https://leetcode.com/problems/3sum/)
<br>
**Tags:** `#array`, `#two-pointers`, `#sorting`

---

## The "Aha!" Moment / Core Idea
The key to solving this efficiently is to first **sort the array**. After sorting, you can iterate through the array, fixing one number `nums[i]`. The problem then reduces to a simpler, classic problem: "Find two numbers in the rest of the array that sum up to `-nums[i]`." This subproblem can be solved in linear time using the **two-pointers** technique.

---

## Approach & Data Structures
**Algorithm:** **Sort + Two Pointers**.
<br>
**Main Data Structure:** The input `vector` is sorted and then iterated through. No complex data structures are needed.
<br>
**Logic:** The solution uses a main `for` loop to fix the first element of the potential triplet. Inside this loop, two pointers (`left` and `right`) are used to scan the remainder of the array to find the other two elements. Crucially, checks are added to skip duplicate numbers to ensure the uniqueness of the resulting triplets.

---

## How It Works
The solution is a highly efficient, in-place algorithm that relies on the array being sorted.

1.  **Sorting and the Main Loop**
    ```cpp
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
        // Skip duplicate elements for 'i'
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        // ... two-pointer logic ...
    }
    ```
    **Logic:** The array is sorted first. The main `for` loop iterates through the array to pick the first element of a potential triplet, `nums[i]`. The `if` condition is a critical optimization that skips over any duplicate values for `nums[i]` to avoid generating the same triplet multiple times.
    <br>
    **Why:** Sorting allows us to use the efficient two-pointer approach and makes it easy to handle duplicates by simply comparing an element to its predecessor.

2.  **The Two-Pointer Search**
    ```cpp
    int left = i + 1;
    int right = nums.size() - 1;
    int target = -nums[i];
    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            // Found a triplet, add it to the answer
            ans.push_back({nums[i], nums[left], nums[right]});
            
            // Move pointers and skip duplicates
            left++;
            right--;
            while (left < right && nums[left] == nums[left - 1]) left++;
            while (left < right && nums[right] == nums[right + 1]) right--;

        } else if (sum < target) {
            left++; // Sum is too small, need a larger number
        } else { // sum > target
            right--; // Sum is too large, need a smaller number
        }
    }
    ```
    **Logic:** For each `nums[i]`, two pointers, `left` and `right`, are initialized at the start and end of the remaining part of the array. They move towards each other based on whether their sum is too small, too large, or exactly equal to the `target` (`-nums[i]`).
    <br>
    **Why:** On a sorted array, this pattern efficiently checks all possible pairs in linear time. If the sum is too small, we must move the `left` pointer to get a larger number. If the sum is too big, we must move the `right` pointer to get a smaller number. When a match is found, we must also skip any subsequent duplicate numbers for `left` and `right` to ensure unique triplets.

---

## Complexity Analysis
* **Time Complexity:** $O(N^2)$ - The initial sort takes $O(N \log N)$. The nested loop structure, where the outer loop runs $N$ times and the inner two-pointer loop runs up to $N$ times, results in a dominant $O(N^2)$ complexity.
* **Space Complexity:** $O(1)$ or $O(\log N)$ - No extra space is used besides the answer vector. The space complexity depends on the implementation of the sorting algorithm used (it can be $O(\log N)$ for the recursion stack).

---

## Key Learnings / Pitfalls
* This is a canonical problem that demonstrates how sorting an array can enable a much more efficient algorithm (from a brute-force $O(N^3)$ down to $O(N^2)$).
* Handling duplicates is the trickiest part. Skipping duplicates for all three pointers (`i`, `left`, and `right`) is essential for a correct solution.
* The two-pointer pattern on a sorted array is a fundamental technique for solving many search and enumeration problems.
