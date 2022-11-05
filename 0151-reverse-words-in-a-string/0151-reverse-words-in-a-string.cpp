class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
       int i=0;
        int n=s.size();
        while(n>i+1)
        {
            
            if(s[i]==' '&& s[i+1]==' ')
            {
                s.erase(i,1);
            }
            else
                i++;
        }
        while(s[0]==' ')
        {
            s.erase(0,1);
        }
        while(s.back()==' ')
        {
            s.pop_back();
        }
        vector<int> ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')ans.push_back(i);
        }
        if(ans.size()>0){
        int prev=0,last=s.size()-1;
        reverse(s.begin(),s.begin()+ans[0]);
        for(int i=1;i<ans.size();i++)
        {
            reverse(s.begin()+ans[i-1]+1,s.begin()+ans[i]);
        }
        reverse(s.begin()+ans.back()+1,s.end());
        }
        else
        {
            reverse(s.begin(),s.end());
        }
        return s;
    }
};