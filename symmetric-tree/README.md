
### 💡 Problem: Symmetric Tree

* **Link:** [https://leetcode.com/problems/symmetric-tree/](https://leetcode.com/problems/symmetric-tree/)
* **Tags:** `#tree`, `#recursion`, `#DFS`, `#BFS`

***

#### The "Aha!" Moment / Core Idea
> The key is that a tree is symmetric if its left and right subtrees are mirror images of each other. This means you can't just traverse one tree; you need a helper function that compares **two nodes** at the same time: one from the left side and one from the right, following a mirrored path down the tree.

***

#### Approach & Data Structures
1.  **Traversal Method:** A recursive, depth-first approach is the most intuitive.
2.  **Helper Function:** A helper function `isMirror(node1, node2)` is used to perform the comparison.
3.  **Logic:** The helper function checks for symmetry by performing a "cross-comparison": it recursively compares the left child of `node1` with the right child of `node2`, and the right child of `node1` with the left child of `node2`.

***

#### Complexity Analysis
* **Time Complexity:** O(N) - Every node in the tree is visited exactly once.
* **Space Complexity:** O(H) - The space is determined by the height of the recursion stack. In the worst case (a skewed tree), the height (H) can be N. In a balanced tree, it's O(log N).

***

#### Key Learnings / Pitfalls
* The problem requires comparing two subtrees, not just one. A helper function taking two nodes is the standard pattern.
* The base cases are critical: handle `nullptr` checks before attempting to access node values to prevent errors.
* The recursive step must be a "cross-comparison": `left` vs. `right` and `right` vs. `left`.
