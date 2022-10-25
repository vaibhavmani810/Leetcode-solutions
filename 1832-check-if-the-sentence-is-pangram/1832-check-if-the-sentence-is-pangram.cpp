class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> fr(26,0);
        for(auto x:sentence)fr[x-'a']++;
        for(int i=0;i<26;i++)
        {
            if(fr[i]==0)return false;
        }
        return true;
    }
};