class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        else
        {
            string res=s.substr(1,s.size())+s[0];
            int n=2*s.size();
            while(n--)
            {
                s=min(s,res);
                res=res.substr(1,res.size())+res[0];
            }
            return s;
        }
    }
};