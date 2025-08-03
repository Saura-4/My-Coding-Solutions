# 💡 Problem: Remove Outer Parentheses
[Link](https://leetcode.com/problems/remove-outermost-parentheses/)
<br>
**Tags:** `#string`, `#stack`, `#simulation`

---

## The "Aha!" Moment / Core Idea
The key is that this problem can be solved in a **single pass** using a simple **balance counter**. A parenthesis is "outer" if it's the one that takes the balance from `0` to `1` (for `(`) or from `1` to `0` (for `)`). All other parentheses are "inner" and should be kept.

---

## Approach & Data Structures
**Traversal Method:** A single **for loop** iterates through the string character by character.
<br>
**Main Data Structure:** An **integer `balance`** is used to keep track of open parentheses.
<br>
**Logic:** The algorithm decides whether to append the current character to the result string based on the `balance` counter's value *before* the counter is updated for that character.

---

## How It Works
The solution iterates through the string, maintaining a `balance` counter to understand the nesting depth. It selectively adds characters to the result string based on the following logic:

1.  **Handling Opening Parentheses `(`**
    ```cpp
    if (c == '(') {
        if (balance > 0) {
            ans += c;
        }
        balance++;
    }
    ```
    **Logic:** An opening parenthesis is only added to the result if the `balance` is already greater than `0`.
    <br>
    **Why:** The very first `(` of any primitive string is found when `balance` is exactly `0`. The condition `balance > 0` is false, so this outermost parenthesis is skipped. All subsequent, "inner" opening parentheses are found when `balance` is already `1` or more, so they are added to the result.

2.  **Handling Closing Parentheses `)`**
    ```cpp
    else { // c must be ')'
        if (balance > 1) {
            ans += c;
        }
        balance--;
    }
    ```
    **Logic:** A closing parenthesis is only added to the result if the `balance` is greater than `1`.
    <br>
    **Why:** The final closing `)` of any primitive string is found when `balance` is exactly `1`. The condition `balance > 1` is false, so this outermost parenthesis is skipped. All "inner" closing parentheses are found when `balance` is `2` or greater, so they are added to the result.

---

## Complexity Analysis
* **Time Complexity:** $O(N)$ - We iterate through the string of length $N$ exactly once.
* **Space Complexity:** $O(N)$ - In the worst case, the result string can be close to the size of the input string.

---

## Key Learnings / Pitfalls
* A problem that seems to require a stack can often be solved more efficiently with a simple counter if you only need to know the current balance.
* The order of operations is crucial: checking the `balance` **before** updating it is key to correctly identifying the outer parentheses.
