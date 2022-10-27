class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>> v1;
        vector<vector<int>> v2;
        int n=img1.size();
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (img1[i][j]==1){
                    v1.push_back({i,j});
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (img2[i][j]==1){
                    v2.push_back({i,j});
                }
            }
        }
        int ans=0;
        map<pair<int,int>,int> mp;
        for (int i=0;i<v1.size();i++){
            //cout<<v1[i][0]<<"   "<<v1[i][1]<<endl;
            for (int j=0;j<v2.size();j++){
                int x1=v2[j][0]-v1[i][0];
                int x2=v2[j][1]-v1[i][1];
                mp[{x1,x2}]++;
                //cout<<x1<<"   "<<x2<<"   "<<mp[{x1,x2}]<<endl;
                ans=max(ans,mp[{x1,x2}]);
            }
        }
        return ans;
    }
};