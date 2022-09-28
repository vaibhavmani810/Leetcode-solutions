class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> l(nums.size(), 1);
        vector<int> r(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]) l[i] = l[i-1]+1;
            else l[i] = 1;
        }
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] <= nums[i+1]) r[i] = r[i+1]+1;
            else r[i] = 1;
        }
        vector<int> ans;
        for(int i = k; i < nums.size()-k; i++)
            if((l[i-1] >= k) && (r[i+1] >= k)) ans.push_back(i);
        
        return ans;
    
    }
};