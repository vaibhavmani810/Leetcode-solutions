class Solution {
public:
  int maxxsum(vector<int>& A)
{
    int max_so_far = 0;
    int max_ending_here = 0;
      int n=A.size();
    for ( int i = 0;i<=n-1;i++ )
    {
        max_ending_here += A[i];
        
        if( max_ending_here < 0 )
            max_ending_here = 0;
        
        max_so_far = max(max_so_far, max_ending_here);
    }
   return max_so_far;
}
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dif1,dif2;
        int ans1=0,ans2=0;
        for(int i=0;i<nums1.size();i++)
        {
            dif1.push_back(nums1[i]-nums2[i]);
            dif2.push_back(nums2[i]-nums1[i]);
            ans1+=nums1[i];
            ans2+=nums2[i];
        }
        int sum1=maxxsum(dif1);
        int sum2=maxxsum(dif2);
        return max(ans1+sum2,ans2+sum1);
    }
};