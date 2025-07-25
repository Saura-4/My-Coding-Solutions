### 💡 Problem: Binary Tree Paths

* **Link:** [https://leetcode.com/problems/binary-tree-paths/](https://leetcode.com/problems/binary-tree-paths/)
* **Tags:** `#tree`, `#recursion`, `#DFS`, `#backtracking`

***

#### The "Aha!" Moment / Core Idea
> The key is to use a Depth-First Search (DFS) to explore every path from the root to a leaf. A helper function must keep track of the current path, and when a leaf is found, that path is formatted and saved. Crucially, you must **backtrack** by removing a node from the path after exploring its children.

***

#### Approach & Data Structures
1.  **Traversal Method:** A recursive, pre-order DFS is used to explore all root-to-leaf paths.
2.  **Helper Function:** A helper function `helper(node, temp, ans)` is used. It passes a temporary vector `temp` to build the current path and a reference to the final `ans` vector.
3.  **Logic:** The helper adds the current node to `temp`. If the node is a leaf, the path is converted to a string and added to `ans`. Then, it recursively calls on the children. After the calls return, it removes the current node from `temp.pop_back()` to backtrack.

***

#### Complexity Analysis
* **Time Complexity:** $O(N \cdot H)$, where N is the number of nodes and H is the tree height. In the worst case, building the path string for each leaf can be expensive.
* **Space Complexity:** $O(H)$ for the recursion stack depth.

***

#### Key Learnings / Pitfalls
* This problem is a classic example of **backtracking** in a tree. Forgetting to `pop_back()` is the most common mistake.
* The logic for converting a vector of integers into a formatted "->" string is a useful sub-problem.
* A helper function that passes the path and the final answer list by reference is the standard, clean pattern for this type of problem.
