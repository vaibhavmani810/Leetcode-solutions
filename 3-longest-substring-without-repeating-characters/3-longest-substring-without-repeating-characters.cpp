class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0;
        map<char,int> mp;
        int len=0;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                while(s[start]!=s[i])
                {
                 mp.erase(s[start]);
                start++;
                }
                mp.erase(s[start]);
                start++;
            }
            mp[s[i]]++;
            
            len=max(len,i-start+1);
            
        }
        return len;
    }
};