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
class Solution {
public:
    
    string tree2str(TreeNode* root) {
        if(!root)return "";
        string x=to_string(root->val);
        if(!root->left && !root->right)return x+"";
        if(!root->right)return x+"("+tree2str(root->left)+")";
        return x+"("+tree2str(root->left)+")"+"("+tree2str(root->right)+")";
    }
};