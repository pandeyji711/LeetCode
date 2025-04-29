class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxx=*max_element(nums.begin(),nums.end());
        int l=0;
        int r=0;
        long long  n=nums.size();
        long long ans=0;
        int cnt=0;
          while(r<n)
          {
                if(nums[r]==maxx)
                cnt++;
                while(cnt>=k)
                {
                      ans+=n-r;
                      if(nums[l]==maxx)
                      cnt--;
                      l++;
                }
                r++;
                
          }
          return ans;
    }
};