class Solution {
public:
    int minMutation(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(auto word:wordList)
            s.insert(word);    
        if(s.count(endWord)==0) return -1;
        int depth=0;
        queue<string> q;
        q.push(beginWord);
        string str="ACGT";
        while(!q.empty())
        {
            depth++;
            int n=q.size();
            while(n--)
            {
                string curr=q.front();
                q.pop();
                
                for(int i=0;i<curr.size();i++)
                {
                    string temp=curr;
                    for(auto c:str)
                    {
                        temp[i]=c;
                        if(temp==curr)continue;
                        if(temp==endWord) return depth;
                        if(s.count(temp)>0)
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return -1;
        
    }
};