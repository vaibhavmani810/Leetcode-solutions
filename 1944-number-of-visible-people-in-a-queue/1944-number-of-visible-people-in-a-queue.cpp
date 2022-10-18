class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        vector<int> ans;
        int n=heights.size();
        for(int i=n-1;i>=0;i--)
        {
            int cnt=0;
            while(!s.empty() && heights[i]>s.top())
            {
                s.pop();
                cnt++;
            }
            if(!s.empty())cnt++;
            s.push(heights[i]);
            ans.push_back(cnt);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};