#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * @brief Checks if a tree is a mirror of itself.
     */
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric.
        if (root == nullptr) {
            return true;
        }
        // Start the recursive helper on the left and right subtrees.
        return isMirror(root->left, root->right);
    }

private:
    /**
     * @brief Helper function to check if two subtrees are mirror images.
     */
    bool isMirror(TreeNode* node1, TreeNode* node2) {
        // Base Case 1: If both nodes are null, they are mirrors.
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }

        // Base Case 2: If one is null but the other isn't, they are not mirrors.
        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }

        // Base Case 3: If the values don't match, they are not mirrors.
        if (node1->val != node2->val) {
            return false;
        }

        // Recursive Step: Perform the cross-comparison.
        // The outer subtrees (left of node1, right of node2) must be mirrors,
        // AND the inner subtrees (right of node1, left of node2) must be mirrors.
        return isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
    }
};
