class Solution {
public:
    int find(int i, vector<int> &parent)
    {
        if (parent[i] == i)
            return i;
 
        return parent[i] = find(parent[i],parent);
    }
    void unite(int x, int y, vector<int> &rank, vector<int> &parent)
    {
        int s1 = find(x,parent);
        int s2 = find(y,parent);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int count=0;
        vector<int> parent(n,-1);
        vector<int> rank(n,1);

        for(int i=0; i<n; i++)
            parent[i]=i;
        
        for(int i=0; i<stones.size(); i++)
            for(int j=i+1; j<stones.size(); j++)
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                    unite(i,j,rank,parent);
                    
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i) count++; 
        }
        return stones.size()-count;
    }
};