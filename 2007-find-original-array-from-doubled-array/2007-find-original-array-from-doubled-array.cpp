class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        multiset<int> s;
        for(auto x:changed)s.insert(x);
        while(!s.empty())
        {
            auto temp=s.begin();
            int val=*temp;
            s.erase(temp);
            auto double_val=s.find(2*val);
            if(double_val==s.end())
            {
             return {};
            }
            ans.push_back(val);
            s.erase(double_val);
        }
        return ans;
    }
};