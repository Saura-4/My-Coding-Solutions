/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    public:
    void helper(TreeNode* root,vector<int>& temp, vector<string>& ans)
    {
        temp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) 
        {
            string s="";
            
            int l=temp.size();
            for(int i=0;i<l;i++)
            {
                s=s+to_string(temp[i]);
                if(i<l-1)
                s=s+"->";
            }
            ans.push_back(s);
        }
        if(root->left!=nullptr)helper(root->left,temp,ans);
        if(root->right!=nullptr)helper(root->right,temp,ans);
        temp.pop_back();

    }
    

        vector<string> binaryTreePaths(TreeNode* root) 
        {
        vector<string> ans;
        if(root==nullptr) return ans;
        vector<int>temp;
        helper(root,temp,ans);
        return ans;
        }
        
        
    
};
