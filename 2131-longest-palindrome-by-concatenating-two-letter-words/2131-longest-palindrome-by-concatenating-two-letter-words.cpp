class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        int ans=0,mila=0;
        for(auto x:words)
        {
            string temp=x;
            swap(temp[0],temp[1]);
            if(mp.find(temp)==mp.end())
            {
                mp[x]++;
            }
            else
            {
                ans+=4;
                mp[temp]--;
                if(mp[temp]==0)mp.erase(temp);
            }
        }
       for(auto x:mp)
       {
           if(x.first[0]==x.first[1])
           {
               ans+=2;
               break;
           }
       }
        return ans;
    }
};