class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        vector<int> fr1(26,0),fr2(26,0);
        for(auto x:word1)
        {
            fr1[x-'a']++;
        }
        for(auto x: word2)
        {
            fr2[x-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(fr1[i]!=fr2[i])
            {
                if(fr1[i]==0||fr2[i]==0)return false;
                
            }
        }
        sort(fr1.begin(),fr1.end());
        sort(fr2.begin(),fr2.end());
        return fr1==fr2;
    }
};