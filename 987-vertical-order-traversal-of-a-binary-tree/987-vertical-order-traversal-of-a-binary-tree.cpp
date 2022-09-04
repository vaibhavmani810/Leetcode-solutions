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
   
map< int,vector<pair<int,int>> > m;
void preorder(TreeNode* root,int lvl=0,int hd=0)
{
  if(!root)
     return;

    pair<int,int> p={lvl,root->val};
    m[hd].push_back(p);   //as vector of pairs
    
    preorder(root->left,lvl+1,hd-1);
    preorder(root->right,lvl+1,hd+1);
    
}

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    vector<vector<int>> v;
    preorder(root);
    
    //now map is filled with diff hd with their values as vector<pair>
    
    for(auto i=m.begin();i!=m.end();i++)
    {
//sorts priority wise -> sort according to first values if same then sort       acc to second value of pair
        sort(i->second.begin(),i->second.end());
        
        vector<int> curr;
        
        for(int j=0;j<i->second.size();j++)
            curr.push_back(i->second[j].second);
        
        v.push_back(curr);
    }
    
    return v;
}
};