class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        map<long long ,int> mp;
        mp[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum%k)==mp.end())
            {
                mp[sum%k]=i+1;
            }
            else
            {
                if(mp[sum%k]<i)return true;
            }
        }
        return false;
    }
};