class Solution {
public:
    static bool cmp(pair<int,string> p1,pair<int,string> p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>> pq;
        map<string,int> mp;
        for(auto s: words) mp[s]++;
         for(auto i:mp)
         {
             pair<int,string> p;
             p.second=i.first;
             p.first=i.second;
             pq.push_back(p);
         }
        sort(pq.rbegin(),pq.rend(),cmp);
        vector<string> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq[i].second);
        }
       
        return ans;
    }
};