class Solution {
public:
    bool help(vector<vector<char>>& board,string word,int i,int j,vector<vector<int>>& vis)
    {
        if(word.size()==0)return true;
        if(i<0||j<0||i==board.size()||j==board[0].size()||vis[i][j])return false;
        if(word[0]!=board[i][j])return false;
        vis[i][j]=1;
        bool d1=help(board,word.substr(1),i+1,j,vis);
         bool d2=help(board,word.substr(1),i,j+1,vis);
         bool d3=help(board,word.substr(1),i-1,j,vis);
         bool d4=help(board,word.substr(1),i,j-1,vis);
        vis[i][j]=0;
        return d1||d2||d3||d4;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                int index=0;
                if(help(board,word,i,j,vis))return true;
            }
        }
        return false;
    }
};