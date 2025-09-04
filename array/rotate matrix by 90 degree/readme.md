# 💡 Problem: Rotate Image
[Link](https://leetcode.com/problems/rotate-image/)
<br>
**Tags:** `#array`, `#matrix`, `#math`

---

## The "Aha!" Moment / Core Idea
The key to an efficient **in-place** rotation is to think of the matrix in **concentric layers** or squares. For each layer, you can rotate the elements by performing a cyclic, four-way swap on the corner elements of that layer. By iterating from the outermost layer to the innermost, the entire matrix can be rotated without using any extra space.



---

## Approach & Data Structures
**Algorithm:** An **in-place, layer-by-layer** rotation.
<br>
**Main Data Structure:** The input `matrix` itself is modified. Two integer indices, `i` and `j`, are used to define the layers and the position within each layer.
<br>
**Logic:** Nested loops iterate through the top-left quadrant of each concentric square of the matrix. For each element, a four-way cyclic swap is performed with its three corresponding corner elements in the other quadrants of that square.

---

## How It Works
The solution breaks the matrix down into layers and rotates each one individually by swapping elements in a cycle.

1.  **The Loops (Iterating Through Layers)**
    ```cpp
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - 1 - i; ++j) {
            // Swap logic goes here...
        }
    }
    ```
    **Logic:** The outer loop `i` iterates from the outermost layer (`0`) to the center of the matrix (`n / 2`). The inner loop `j` iterates along the top edge of the current layer. The bounds `j = i` and `j < n - 1 - i` cleverly ensure that we only iterate over the elements that are the starting point of a four-element group to be rotated.
    <br>
    **Why:** This loop structure guarantees that every element is moved exactly once as part of a four-way swap, and no element is rotated more than it should be. It effectively covers the entire matrix by only iterating through a quarter of its cells.

2.  **The Four-Way Swap**
    For each element `matrix[i][j]`, we perform a cyclic swap with its three corresponding corners.

    ```cpp
    // The four corners for a given (i, j) are:
    // Top-Left:      matrix[i][j]
    // Top-Right:     matrix[j][n - 1 - i]
    // Bottom-Right:  matrix[n - 1 - i][n - 1 - j]
    // Bottom-Left:   matrix[n - 1 - j][i]

    // A clever 3-swap rotation (without a temp variable)
    swap(matrix[i][j], matrix[j][n - 1 - i]);
    swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
    swap(matrix[i][j], matrix[n - 1 - j][i]);
    ```
    **Logic:** A sequence of three swaps involving the top-left element `matrix[i][j]` correctly rotates the values of the four corner elements in a clockwise direction.
    <br>
    **Why:** This is an efficient in-place method to perform a cyclic permutation. The first swap moves the top-right value to the top-left. The second swap moves the bottom-right value to the (new) top-left and sends the original top-right value to the bottom-right. The final swap completes the cycle.

---

## Complexity Analysis
* **Time Complexity:** $O(N^2)$ - The nested loops iterate through roughly $N^2 / 4$ elements, and we perform a constant number of operations for each. This simplifies to $O(N^2)$.
* **Space Complexity:** $O(1)$ - The rotation is performed **in-place**, without allocating any new data structures.

---

## Key Learnings / Pitfalls
* The problem can also be solved with another common trick: first, **transpose** the matrix (swap `matrix[i][j]` with `matrix[j][i]`), and then **reverse each row**.
* The loop boundaries (`n / 2` and `n - 1 - i`) are the most critical part of this algorithm and are easy to get wrong. They are key to preventing elements from being rotated back to their original positions.
* A four-way cyclic swap is a useful pattern for in-place matrix manipulations.
