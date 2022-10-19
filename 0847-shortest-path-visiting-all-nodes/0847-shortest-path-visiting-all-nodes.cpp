class node{
    public:
    int value;
    int cost;
    int mask;
    node(int value,int mask,int cost)
    {
        this->value=value;
        this->cost=cost;
        this->mask=mask;
    }
    
};
// in this we are genrating every possible path and checking whter it is minimum or not.
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<node> q;
        set<pair<int,int>> st;
        for(int i=0;i<n;i++)
        {
            node cur(i,1<<i,1);
            q.push(cur);
            st.insert({i,i<<i});
        }
        int all=((1<<n)-1);
        while(!q.empty())
        {
            node cur=q.front();
            q.pop();
            if(cur.mask==all)
            {
                return cur.cost-1;
            }
            for(auto &nbr:graph[cur.value])
            {
                int bothvis=cur.mask;
                bothvis|=(1<<nbr);
                if(st.count({nbr,bothvis})==0)
                {
                    st.insert({nbr,bothvis});
                    q.push({nbr,bothvis,cur.cost+1});
                }
            }
        }
        return -1;
    }
};