class Solution {
public:
    # define ll long long
    int threeSumClosest(vector<int>& nums, int target) {
        // step 1 sort the array
        // step apply two pointer
        sort(nums.begin(),nums.end()); // sort the array
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++) // 1 2 3
        {
            int j=i+1;
            int l=nums.size()-1;
            while(j<l)
            {
                long long sum=((ll)nums[i]+(ll)nums[j]+(ll)nums[l]);
                if(sum==target)
                {
                    return sum;
                }
                else if(sum<target)
                {
                    j++;
                }
                else
                    l--;
                if(abs(target-ans)>abs(sum-target))ans=sum;
            }
                
        }
        return ans;
    }
};