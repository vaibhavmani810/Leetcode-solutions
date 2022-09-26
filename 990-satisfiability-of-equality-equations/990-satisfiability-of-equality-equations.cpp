class Solution {
public:
    map<char,list<char>> mp;
    
    bool dfs_helper(char src,char des,map<char,bool> &visited)
    {
        if(src==des)
            return true;

        visited[src]=true;
        
        for(auto nbr: mp[src])
        {
            if(!visited[nbr])
            {
                if(dfs_helper(nbr,des,visited))
                    return true;
            }
        }
        
        return false;
    }
    
    bool dfs(char src,char des)
    {
        map<char,bool> visited;
        
        return dfs_helper(src,des,visited);
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(auto s:equations)
        {
            if(s[1]=='=')
            {
                mp[s[0]].push_back(s[3]);
                mp[s[3]].push_back(s[0]);
            }
        }
        
        for(auto s:equations)
        {
            if(s[1]=='!')
            {
                if(dfs(s[0],s[3])==true)
                    return false;
            }
        }
        
        return true;
    }
};