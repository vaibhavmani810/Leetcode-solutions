class Solution {
public:
   int minCost(string colors, vector<int>& neededTime) {
    int ans=0;
    char p=colors[0];
    int pre=0;
    for(int i=1;i<colors.size();i++){
        if(p==colors[i]){
          if(neededTime[pre]<neededTime[i]){
              ans+=neededTime[pre];
              
              pre=i;
              p=colors[pre];
          }
            else{
                ans+=neededTime[i];
                
            }
        }
        else{
            p=colors[i];
            pre=i;
        }
    }
    return ans;
}
};