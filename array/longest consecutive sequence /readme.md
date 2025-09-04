# 💡 Problem: Longest Consecutive Sequence
[Link](https://leetcode.com/problems/longest-consecutive-sequence/)
<br>
**Tags:** `#array`, `#hash-set`, `#union-find`

---

## The "Aha!" Moment / Core Idea
The key to an $O(N)$ solution is to use a **hash set** for instant lookups. The main insight is to avoid redundant counting. Instead of checking every number, we only start counting a sequence when we find its true starting point. A number `x` is the start of a sequence if and only if `x - 1` is **not** present in the set.

---

## Approach & Data Structures
**Algorithm:** A single pass to build a set, followed by a second pass to identify and count sequences.
<br>
**Main Data Structure:** An `unordered_set` (hash set) is used to store all the numbers from the input array. This allows for $O(1)$ average time complexity for insertion and lookup.
<br>
**Logic:** The algorithm iterates through the numbers in the set. For each number, it checks if it's the start of a sequence. If it is, it then counts how long that sequence is by repeatedly checking for the next consecutive number in the set.

---

## How It Works
The solution efficiently finds the longest sequence by ensuring it only ever counts each sequence once, starting from its smallest number.

1.  **Storing the Numbers**
    ```cpp
    unordered_set<int> num_set(nums.begin(), nums.end());
    ```
    **Logic:** First, all numbers from the input vector `nums` are added to a hash set called `num_set`.
    <br>
    **Why:** This allows us to check for the existence of any number in approximately $O(1)$ time, which is much faster than repeatedly searching through the original array. This step also implicitly handles duplicates.

2.  **Finding and Counting Sequences**
    ```cpp
    for (int num : num_set) {
        // Check if 'num' is the start of a sequence
        if (!num_set.count(num - 1)) {
            int current_num = num;
            int current_streak = 1;

            // Count the length of the sequence
            while (num_set.count(current_num + 1)) {
                current_num++;
                current_streak++;
            }
            
            longest_streak = max(longest_streak, current_streak);
        }
    }
    ```
    **Logic:** The code iterates through every number in the set. The `if (!num_set.count(num - 1))` condition is the most important part—it checks if the current number is a starting point. If it is, a `while` loop is used to count how many consecutive numbers (`num + 1`, `num + 2`, etc.) also exist in the set.
    <br>
    **Why:** This check is a crucial optimization. Without it, you would start a count for every single number, leading to a lot of repeated work. By only starting a count when you find the "true" beginning of a sequence, you guarantee that the inner `while` loop will run, in total, only $N$ times across the entire execution.

---

## Complexity Analysis
* **Time Complexity:** $O(N)$ - Although there is a nested loop, each number is only ever visited by the inner `while` loop once as part of a sequence. Therefore, the total time is linear.
* **Space Complexity:** $O(N)$ - In the worst case, the hash set will need to store all $N$ numbers from the input array.

---

## Key Learnings / Pitfalls
* This problem demonstrates how using the right data structure (a **hash set**) can dramatically improve time complexity from $O(N \log N)$ (for a sorting-based solution) to $O(N)$.
* The optimization of only starting a search from the beginning of a sequence (by checking for the absence of `num - 1`) is a key pattern for this type of problem.
