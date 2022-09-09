class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0]!=b[0])return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
       sort(pro.begin(),pro.end(),cmp);
        int ans=0,maxx=pro[0][1];
        for(auto x:pro)
        {
            if(maxx<=x[1])maxx=x[1];
            else ans++;
        }
        return ans;
    }
};