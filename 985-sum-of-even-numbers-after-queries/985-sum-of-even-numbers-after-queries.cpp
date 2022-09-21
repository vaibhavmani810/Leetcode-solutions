class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0,even_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]%2==0)even_sum+=nums[i];
            else
                sum+=nums[i];
        }
        
        vector<int> arr;
        for(auto x:queries)
        {
            if((nums[x[1]]+x[0])%2==0)
            {
                if(nums[x[1]]%2==0)even_sum-=nums[x[1]];
                nums[x[1]]+=x[0];
                even_sum+=nums[x[1]];
            }
            else
            {
                if(nums[x[1]]%2==0)
                {
                    even_sum-=nums[x[1]];
                }
                nums[x[1]]+=x[0];
            }
            arr.push_back(even_sum);
        }
        return arr;
    }
};