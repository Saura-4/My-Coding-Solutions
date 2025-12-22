# 💡 Problem: Longest Common Prefix
[Link](https://leetcode.com/problems/longest-common-prefix/)
<br>
**Tags:** `#string`, `#simulation`

---

## The "Aha!" Moment / Core Idea
The key is to assume the **first word is the longest possible prefix** and then iteratively shorten it by comparing it against every other word in the list. The prefix can only get shorter or stay the same with each comparison.

---

## Approach & Data Structures
**Traversal Method:** This approach is known as **Horizontal Scanning**. It uses nested loops. The outer loop iterates through the list of strings, and the inner loop compares the characters of the current prefix with the current string.
<br>
**Main Data Structure:** A `string` variable holds the longest common prefix found so far, which is updated after each comparison.
<br>
**Logic:** Start with `prefix = strs[0]`. For each subsequent string in the array, find the number of matching characters from the beginning. Update the prefix by resizing it to this new, possibly shorter, length. If the prefix ever becomes empty, stop early.

---

## How It Works
The solution initializes the `ans` variable with the first string in the array. It then iterates through the rest of the strings, effectively "chipping away" at `ans` until it matches the common prefix of all strings seen so far.

1.  **Initialization and Outer Loop**
    ```cpp
    string ans = strs[0];
    for(int i = 1; i < strs.size(); i++) {
        // ... comparison logic ...
    }
    ```
    **Logic:** `ans` starts as the longest possible prefix. The loop then compares this `ans` against every other string.
    <br>
    **Why:** This sets up a baseline. The final common prefix cannot be longer than the first string.

2.  **Inner Loop and Prefix Update**
    ```cpp
    int match = 0;
    for (int j = 0; j < s; j++) { // s is the min length of ans and strs[i]
        if (ans[j] == strs[i][j]) {
            match++;
        } else {
            break;
        }
    }
    ans.resize(match);
    ```
    **Logic:** For each string, a second loop counts the number of characters that match from the beginning. After the loop, `ans` is resized to the `match` count.
    <br>
    **Why:** This correctly finds the common prefix between the current `ans` and the string being checked. The `resize` operation updates `ans` to this new, potentially shorter prefix before it's compared against the next string in the array. This ensures `ans` is always the common prefix of all strings processed so far.

---

## Complexity Analysis
* **Time Complexity:** $O(S)$, where S is the sum of all characters in all strings. In the worst case, every character of every string is compared.
* **Space Complexity:** $O(1)$ - We only use a few variables to store the prefix and loop counters, not proportional to the input size.

---

## Key Learnings / Pitfalls
* This horizontal scanning approach is intuitive and easy to implement.
* It's important to handle the edge case where the input list of strings is empty.
* The `resize` or `substr` method is key to shortening the prefix after each comparison. An optimization is to stop the entire process if the prefix ever becomes an empty string.
