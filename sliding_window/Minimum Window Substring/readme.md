# 💡 Problem: Minimum Window Substring
[Link](https://leetcode.com/problems/minimum-window-substring/)
<br>
**Tags:** `#string`, `#sliding-window`, `#hash-table`, `#two-pointers`

---

## The "Aha!" Moment / Core Idea
The key to this problem is using a **dynamic sliding window**. Instead of comparing character counts on every slide, we can use a counter system. We track how many unique characters we need (`required`) and how many we currently have satisfied (`formed`). The window expands until `formed == required`, at which point we've found a potential answer. Then, we shrink the window from the left as much as possible while it remains valid, updating our best answer at each step.

---

## Approach & Data Structures
**Algorithm:** A **sliding window** with two pointers (`left` and `right`) is the optimal approach.
<br>
**Main Data Structures:**
* `map<char, int> required_chars`: Stores the frequency of characters required by string `t`.
* `map<char, int> window_chars`: Stores the frequency of characters inside the current `left...right` window.
* **Counters:**
    * `required`: The number of unique characters in `t`.
    * `formed`: The number of unique characters in the current window that meet their required frequency.

**Logic:** The `right` pointer expands the window. When `formed == required`, the window is valid. We then enter a loop to shrink the window from the `left`, updating our best answer, until the window is no longer valid.

---

## How It Works
The algorithm efficiently finds the minimum window by tracking not just the characters, but the state of the window's validity.

1.  **Initialization**
    ```cpp
    map<char, int> required_chars;
    for (char c : t) {
        required_chars[c]++;
    }
    int required = required_chars.size();
    int formed = 0;
    ```
    **Logic:** First, we create a frequency map of all characters in the target string `t`. The number of unique characters is stored in `required`. A `formed` counter is initialized to `0`.
    <br>
    **Why:** This setup tells us exactly what we need to find before we start scanning the main string `s`.

2.  **Expanding the Window**
    ```cpp
    for (int right = 0; right < s.length(); ++right) {
        char c = s[right];
        window_chars[c]++;

        if (required_chars.count(c) && window_chars[c] == required_chars[c]) {
            formed++;
        }
        // ...
    }
    ```
    **Logic:** The `right` pointer expands the window. We update the count of the new character `c` in our `window_chars` map. If `c` is a required character and its count in the window now matches its required count, we increment `formed`.
    <br>
    **Why:** The `formed` counter is our trigger. It efficiently tells us the exact moment our window contains all the necessary characters without needing to re-scan the maps.

3.  **Shrinking the Window**
    ```cpp
    while (left <= right && formed == required) {
        // Update the answer if this window is the new minimum
        if (right - left + 1 < min_length) {
            min_length = right - left + 1;
            start_index = left;
        }

        // Remove the left character from the window
        char left_char = s[left];
        window_chars[left_char]--;

        if (required_chars.count(left_char) && window_chars[left_char] < required_chars[left_char]) {
            formed--;
        }
        
        left++;
    }
    ```
    **Logic:** Once `formed == required`, we enter a `while` loop. First, we check if the current window is the smallest we've seen and update our answer. Then, we shrink the window by moving `left` to the right. As a character leaves the window, we decrement its count in `window_chars`. If that character was required and its count has now dropped below the required amount, we decrement `formed`.
    <br>
    **Why:** This loop's purpose is twofold: to find the smallest possible valid window ending at the current `right`, and to move the `left` pointer forward so the search for the next valid window can continue.

---

## Complexity Analysis
* **Time Complexity:** $O(N + M)$, where $N$ and $M$ are the lengths of strings `s` and `t`. Each pointer (`left` and `right`) traverses the string `s` only once.
* **Space Complexity:** $O(K)$, where $K$ is the number of unique characters in string `t`.

---

## Key Learnings / Pitfalls
* This is a canonical sliding window problem that demonstrates how to manage a window's validity with counters (`formed` and `required`).
* The logic of **expanding until valid, then shrinking until invalid**, is a common and powerful pattern.
* It's more efficient to track the start index and length of the best answer and only create the final substring once at the end.
