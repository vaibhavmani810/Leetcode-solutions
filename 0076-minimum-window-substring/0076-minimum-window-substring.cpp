class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1,mp2;
        for(auto x:t)mp1[x]++;
        int res=(int)mp1.size();
        int start=0;
        int ans=INT_MAX;
        int cnt=0;
        int b=INT_MAX,e=INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            mp2[s[i]]++;
            if(mp2[s[i]]==mp1[s[i]])
            {
                cnt++;
            }
            if(mp1.find(s[i])!=mp1.end())
            {
                while(mp1[s[start]]<mp2[s[start]]&&cnt==res)
                {
                    mp2[s[start]]--;
                    start++;
                }
            }
            if(cnt==res && ans>(i-start+1))
            {
                ans=min(ans,i-start+1);
                b=start;
                e=i;
                
            }
        }
        if(b==INT_MAX)return "";
        return s.substr(b,e-b+1);
    }
};