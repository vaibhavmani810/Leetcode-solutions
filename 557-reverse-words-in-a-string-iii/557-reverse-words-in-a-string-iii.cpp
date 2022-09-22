class Solution {
public:
    string reverseWords(string s) {
       string ans="",s1="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            s1.push_back(s[i]);
            else{
            reverse(s1.begin(),s1.end());
            ans+=s1;
                ans+=" ";
                s1.resize(0);
            }
        }
         reverse(s1.begin(),s1.end());
        ans+=s1;
        return ans;
    }
};