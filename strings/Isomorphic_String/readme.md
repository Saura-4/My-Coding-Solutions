# 💡 Problem: Isomorphic Strings
[Link](https://leetcode.com/problems/isomorphic-strings/)
<br>
**Tags:** `#string`, `#hash-table`, `#map`

---

## The "Aha!" Moment / Core Idea
The key is that an isomorphic relationship is a strict **one-to-one mapping**. It's not enough to check that a character in `s` always maps to the same character in `t`. You must also ensure that no two different characters in `s` map to the same character in `t`. The easiest way to enforce this is to **check the mapping in both directions**.

---

## Approach & Data Structures
**Traversal Method:** A single `for` loop iterates through both strings simultaneously by index.
<br>
**Main Data Structure:** Two maps are used. `map1` stores the forward mapping (`s[i] -> t[i]`), and `map2` stores the reverse mapping (`t[i] -> s[i]`).
<br>
**Logic:** For each pair of characters `s[i]` and `t[i]`, the algorithm checks for consistency in both maps. If a character in `s` tries to map to a new character in `t` but that `t` character is already taken, it's not isomorphic.

---

## How It Works
The solution ensures a consistent one-to-one mapping by using two separate maps to track the relationship from both sides.

1.  **Checking the Forward Mapping (s to t)**
    This part of the code ensures that a character from `s` always maps to the same character in `t`.
    ```cpp
    // For each character s[i]
    if (map1.count(s[i])) { // If we've seen this s-char before
        if (map1[s[i]] != t[i]) {
            return false; // It must map to the same t-char
        }
    } else {
        // This is a new mapping
        map1[s[i]] = t[i];
    }
    ```
    **Logic:** If a character from `s` is already in `map1`, we check if its stored mapping matches the current character from `t`. If it doesn't, the mapping is inconsistent, and the strings are not isomorphic.
    <br>
    **Why:** This handles cases like `s = "egg"`, `t = "ada"`. It correctly maps `'e' -> 'a'`, then `'g' -> 'd'`. When it sees the second `'g'`, it confirms that its mapping is still `'d'`.

2.  **Checking the Reverse Mapping (t to s)**
    This part ensures that no two characters from `s` map to the same character in `t`.
    ```cpp
    // For each character t[i]
    if (map2.count(t[i])) { // If we've seen this t-char before
        if (map2[t[i]] != s[i]) {
            return false; // It must be mapped from the same s-char
        }
    } else {
        // This is a new mapping
        map2[t[i]] = s[i];
    }
    ```
    **Logic:** Symmetrically, we check `map2`. If a character from `t` has already been used in a mapping, we verify that it was mapped from the same character in `s`.
    <br>
    **Why:** This handles cases like `s = "ab"`, `t = "aa"`. The forward mapping would be fine (`'a' -> 'a'`, `'b' -> 'a'`). However, the reverse check fails. When processing `'b' -> 'a'`, the code sees that `'a'` is already in `map2` and is mapped from a different character (the first `'a'` in `s`), so it correctly returns `false`.

---

## Complexity Analysis
* **Time Complexity:** $O(N)$ - We iterate through the strings of length $N$ exactly once.
* **Space Complexity:** $O(K)$ - Where $K$ is the number of unique characters in the string. In the worst case, this is $O(N)$, but it's bounded by the size of the character set (e.g., 256 for ASCII).

---

## Key Learnings / Pitfalls
* Isomorphism and other bijective (one-to-one) relationship problems often require **checking the mapping in both directions**.
* Using two maps is a clear and robust pattern to enforce this two-way check. A single map is not sufficient.
