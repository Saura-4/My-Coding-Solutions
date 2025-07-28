### 💡 Problem: Lowest Common Ancestor of a Binary Tree

* **Link:** [https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
* **Tags:** `#tree`, `#recursion`, `#DFS`

***

#### The "Aha!" Moment / Core Idea
> Instead of using flags or passing down extra state, the key is to use the function's return value (`TreeNode*`) to signify what was found. A call on a subtree returns `p`, `q`, the `LCA`, or `nullptr`. The LCA is the first node where the recursive calls on its left and right children both return a non-null value.

***

#### Approach & Data Structures
1.  **Traversal Method:** A recursive Depth-First Search (DFS) is used.
2.  **Function Signature:** The function `lowestCommonAncestor(root, p, q)` returns a `TreeNode*`.
3.  **Logic:**
    * **Base Cases:** If the current node is `nullptr`, `p`, or `q`, return it.
    * **Recursive Step:** Recursively call the function on the left and right children.
    * **Decision:**
        * If both left and right calls return a valid node, the current node is the LCA.
        * If only one call returns a valid node, pass that node's pointer up the call stack.
        * If both return `nullptr`, pass `nullptr` up.

***

#### Complexity Analysis
* **Time Complexity:** O(N) - In the worst case, we visit every node in the tree once.
* **Space Complexity:** O(H) - The space is determined by the height (H) of the recursion stack. In the worst case of a skewed tree, this can be O(N).

***

#### Key Learnings / Pitfalls
* This is a classic example of using a function's return value to pass rich state information up the recursion stack, which is a very powerful pattern.
* The base cases are crucial: checking for `p` or `q` allows the findings to be propagated up.
* The logic `if (left && right) return root;` is the heart of the solution, identifying the point where the paths to `p` and `q` diverge.
