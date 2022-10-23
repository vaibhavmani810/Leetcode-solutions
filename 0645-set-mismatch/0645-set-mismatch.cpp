class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            int cind = nums[i] - 1;
            if(nums[i] != nums[cind]) {
                swap(nums, i, cind);
            }
            else i++;
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != i + 1) {
                return {nums[i],i + 1};
            }
        }
        return {};
    }
    void swap(vector<int>& vec, int fir, int sec) {
        int n = vec[fir];
        vec[fir] = vec[sec];
        vec[sec] = n;
    }
};