class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
      return [&](){int maxx=*max_element(nums.begin(),nums.end()),l=0,r=0,cnt=0;long long n=nums.size(),ans=0;while(r<n){if(nums[r]==maxx)cnt++;while(cnt>=k){ans+=n-r;if(nums[l]==maxx)cnt--;l++;}r++;}return ans;}();

    }
};