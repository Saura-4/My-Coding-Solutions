# 💡 Problem: Longest Repeating Character Replacement
[Link](https://leetcode.com/problems/longest-repeating-character-replacement/)
<br>
**Tags:** `#string`, `#sliding-window`, `#hash-table`

---

## The "Aha!" Moment / Core Idea
The key is to use a **sliding window** and maintain a count of the characters within it. A window is considered "valid" if the number of characters we need to replace to make them all the same is less than or equal to `k`. This number is simply `(window_length - count_of_the_most_frequent_character)`.

---

## Approach & Data Structures
**Algorithm:** A **sliding window** with two pointers (`i` for left, `j` for right) is used.
<br>
**Main Data Structure:** A frequency map (`map<char, int>`) tracks the counts of each character within the current window.
<br>
**Logic:** The `j` pointer expands the window. After each expansion, we check if the window is valid. If it's invalid, we shrink the window from the left by moving the `i` pointer. The maximum valid window size seen is the answer.

---

## How It Works
The algorithm uses a sliding window to find the longest valid substring. Pointers `i` (left) and `j` (right) define the window's boundaries, and a frequency map tracks the character counts inside it.

1.  **Expanding the Window**
    ```cpp
    for (int j = 0; j < s.size(); j++) {
        mp[s[j]]++;
        maxf = max(maxf, mp[s[j]]);
        // ...
    }
    ```
    **Logic:** The `j` (right) pointer moves from left to right, including a new character in the window with each step. The frequency of this new character is updated in the map, and a `maxf` variable is updated to keep track of the count of the most common character.
    <br>
    **Why:** This process grows the window and maintains the necessary information to check its validity.

2.  **Checking and Shrinking the Window**
    ```cpp
    if ((j - i + 1) - maxf > k) {
        mp[s[i]]--;
        i++;
    }
    ```
    **Logic:** After expanding, we check if the number of "minority" characters (`window_length - max_frequency`) exceeds our replacement budget `k`. If it does, the window is invalid. To fix it, we shrink the window by moving the `i` (left) pointer to the right and decrementing the count of the character that is now leaving the window.
    <br>
    **Why:** This step ensures the window always remains in a valid state. The window never actually shrinks in size, it just slides. The size `(j - i + 1)` is always the candidate for the maximum length, which is implicitly tracked.

---

## Complexity Analysis
* **Time Complexity:** $O(N)$ - The `i` and `j` pointers each traverse the string only once.
* **Space Complexity:** $O(K)$, where $K$ is the number of unique characters. This is $O(1)$ if the character set is fixed (e.g., 26 for the English alphabet).

---

## Key Learnings / Pitfalls
* This is a classic sliding window problem where the validity of the window depends on a calculated property (`window_length - max_frequency`).
* The key optimization is realizing you don't need to recalculate the `maxf` when shrinking the window. We only care about the **all-time maximum frequency** seen so far, because a smaller `maxf` wouldn't lead to a longer valid substring anyway.
