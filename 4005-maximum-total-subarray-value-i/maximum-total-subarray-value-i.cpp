class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
         long long  maxx=*max_element(nums.begin(),nums.end());
         long long minn=*min_element(nums.begin(),nums.end());
         return k*1LL*(maxx-minn);
    }
};