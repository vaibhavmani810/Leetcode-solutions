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
    vector<int> mp;
    int res=0;
    void dfs(TreeNode* root)
    {
        if(!root)return;
        mp[root->val]++;
        if(root->left==nullptr&&root->right==nullptr)
        {
            int cnt=0;
            for(int i=1;i<=9;i++)
            {
                if(mp[i]%2)cnt++;
            }
            if(cnt<=1)res++;
        }
        dfs(root->left);
        dfs(root->right);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        mp.resize(10);
        for(int i=0;i<=9;i++)mp[i]=0;
        dfs(root);
        return res;
    }
};