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
public:vector<vector<int>> ans;
    void help(TreeNode* root,int &sum,vector<int>& res,int target)
    {
        if(root==nullptr)return;
        sum+=root->val;
        res.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr&&sum==target)
        {
            ans.push_back(res);
        }
        help(root->left,sum,res,target);
        help(root->right,sum,res,target);
        sum-=root->val;
        res.pop_back();
         
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> res;
        int sum=0;
        help(root,sum,res,targetSum);
        return ans;
    }
};