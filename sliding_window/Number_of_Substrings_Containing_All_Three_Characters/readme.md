# 💡 Problem: Number of Substrings Containing All Three Characters
[Link](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)
<br>
**Tags:** `#string`, `#sliding-window`, `#hash-table`

---

## The "Aha!" Moment / Core Idea
The key is to use a **sliding window**. Instead of counting valid substrings one by one, we can count them in batches. For a given `left` pointer, once the window `s[left...right]` becomes valid (contains 'a', 'b', and 'c'), we know that this window, and **any larger window starting at `left` and ending after `right`**, is also valid. The number of such substrings is `s.length() - right`.

---

## Approach & Data Structures
**Algorithm:** A **sliding window** with two pointers (`left` and `right`) is used.
<br>
**Main Data Structure:** A frequency map (`map<char, int>` or a simple array of size 3) tracks the counts of 'a', 'b', and 'c' within the current window.
<br>
**Logic:** The `right` pointer expands the window. As soon as the window becomes valid, we add the number of valid superstrings to our answer and then shrink the window from the `left` to find the next valid starting position.

---

## How It Works
The algorithm uses a sliding window to efficiently count all valid substrings in a single pass. The pointers `left` and `right` define the window.

1.  **Expanding the Window**
    ```cpp
    for (int right = 0; right < s.length(); ++right) {
        mp[s[right]]++;
        // ...
    }
    ```
    **Logic:** The `right` pointer moves from left to right, including a new character in the window with each step. The frequency of this character is incremented in the map.
    <br>
    **Why:** This process grows the window and updates the state needed to check if the window contains all three required characters.

2.  **Counting and Shrinking the Window**
    ```cpp
    while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
        ans += (s.length() - right);
        mp[s[left]]--;
        left++;
    }
    ```
    **Logic:** As soon as the window `s[left...right]` becomes valid (contains at least one 'a', 'b', and 'c'), we enter a `while` loop. Inside, we know that the current substring `s[left...right]` is the *first* valid substring starting at `left`. This also means that any substring starting at `left` and ending at `right` or any point after it is also valid. There are `s.length() - right` such substrings. We add this count to our answer. Then, we shrink the window from the left (`mp[s[left]]--; left++;`) to find the next valid substring.
    <br>
    **Why:** This clever counting method avoids iterating through all possible endings. By adding `s.length() - right`, it instantly accounts for all valid substrings that start at the current `left` position. Shrinking the window allows the process to efficiently find the next valid starting point.

---

## Complexity Analysis
* **Time Complexity:** $O(N)$ - The `left` and `right` pointers each traverse the string only once.
* **Space Complexity:** $O(1)$ - The frequency map has a constant size (3), regardless of the input string's length.

---

## Key Learnings / Pitfalls
* This problem showcases a unique counting method within the sliding window pattern, where you count in batches rather than one by one.
* The key is to understand that once a minimal window `s[left...right]` is valid, you can make a conclusion about many other substrings that start at `left`.
* An alternative (and equally valid) way to structure the logic is to expand `right` until the window is valid, and then for every valid `left` pointer, add `s.length() - right` to the count.
