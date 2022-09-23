class Solution {
public:
    int m=1e9+7;
    int concatenatedBinary(int n) {
        long long ans=1;
        for(int i=2;i<=n;i++)
        {
            ans=((ans<<((long long)log2(i)+1))%m+i)%m;
        }
        return (int)ans;
    }
};