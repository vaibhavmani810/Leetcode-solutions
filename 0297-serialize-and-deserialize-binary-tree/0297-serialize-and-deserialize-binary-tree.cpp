/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    string serialize(TreeNode* root) {
        // here we are simple doing preorder and converting every node value to string 
        
        if(root==NULL) return "n"; // base case
        
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
    TreeNode* mytree(string& data)
    {
        if(data[0]=='n')
        {
            if(data.size()>1)
            {
                data=data.substr(2);
            }
            return NULL;
        }
        else
        {   //val = stoi(data.substr(0,data.find(',')));
            TreeNode *temp=new TreeNode((int)stoi(data.substr(0,data.find(','))));
            data=data.substr(data.find(',')+1);
            temp->left=mytree(data);
            temp->right=mytree(data);
         
        
        return temp;
        }
    }
    TreeNode* deserialize(string data) {
        return mytree(data);
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));