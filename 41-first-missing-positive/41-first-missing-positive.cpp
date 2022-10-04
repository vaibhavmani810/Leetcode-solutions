class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l=nums.size();
        for(int i=0;i<nums.size();i++)
        {
             
            while(nums[i]>=1&&nums[i]<=l&&nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
                
            }
        }
        for(int i=0;i<l;i++)
        {
            if((i+1)!=nums[i])
                return i+1;
        }
        return l+1;
        
    }
};