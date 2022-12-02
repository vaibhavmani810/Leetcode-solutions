class Solution {
public:
    // Idea is simple first reverse the whole string and then each word one by one we will get our result
    // there are some another methods also which are easy to implement like using stack but we are trying to excute follow up of O(1) space .
    string reverseWords(string s) {
       reverse(s.begin(),s.end()); // first step reverse whole string
       // remove extra spaces 
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
        // after this point our string will not have any extra space in between
        vector<int> ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')ans.push_back(i); // storing position of spaces to reverse word with the help of spaces
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