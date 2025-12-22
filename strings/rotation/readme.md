# 💡 Problem: Rotate String
[Link](https://leetcode.com/problems/rotate-string/)
<br>
**Tags:** `#string`, `#simulation`

---

## The "Aha!" Moment / Core Idea
While you can solve this by manually simulating each rotation, a much cleaner and more clever trick exists. A string `goal` can be obtained by rotating `s` if and only if `goal` is a substring of `s` concatenated with itself (`s + s`). For example, if `s = "abcde"`, then `s + s = "abcdeabcde"`, which contains all possible rotations like `"cdeab"`.

---

## Approach & Data Structures
**Traversal Method:** The user's solution uses a **Simulation** approach. A `for` loop is used to perform each rotation of the string `s`.
<br>
**Main Data Structure:** A `string` variable is modified in place to represent the rotated string after each shift.
<br>
**Logic:** First, handle edge cases like different string lengths or initially identical strings. Then, loop up to `s.length()` times. In each iteration, perform one left rotation and check if the new string equals `goal`.

---

## How It Works
The solution simulates the process of shifting the first character of `s` to the end and checking for a match after each shift.

1.  **Handling Edge Cases**
    ```cpp
    if (s.length() != goal.length()) {
        return false;
    }
    if (s == goal) {
        return true;
    }
    ```
    **Logic:** The code first checks if the strings have different lengths, which makes a match impossible. It also checks if they are already equal, allowing for an immediate successful exit.
    <br>
    **Why:** These checks handle simple cases efficiently without needing to enter the main loop.

2.  **The Rotation Loop**
    ```cpp
    for (int i = 0; i < s.length(); i++) {
        // Perform one left rotation
        s.push_back(s[0]);
        s.erase(0, 1);
        
        // Check for a match
        if (s == goal) {
            return true;
        }
    }
    ```
    **Logic:** The loop runs `s.length()` times to cover all possible unique rotations. In each step, the first character is moved to the end, and the result is compared to `goal`.
    <br>
    **Why:** This systematically generates every possible rotation of `s`. If a match is ever found, we can immediately return `true`. If the loop completes without a match, we know it's impossible.

---

## Complexity Analysis
* **Time Complexity:** $O(N^2)$ - The loop runs $N$ times, and inside the loop, string operations (like `erase` and comparison) can take up to $O(N)$ time.
* **Space Complexity:** $O(1)$ - The string is modified in place, so no extra space proportional to the input size is used.

---

## Key Learnings / Pitfalls
* The simulation approach is intuitive but can be less performant than the `s + s` trick.
* The `s + s` trick is a classic string manipulation pattern. If `s.length() == goal.length()`, `goal` is a rotation of `s` if and only if `(s + s).find(goal) != string::npos`. This solves the problem in $O(N)$ time.
* Remembering to check for simple edge cases like different lengths can make code more efficient.
