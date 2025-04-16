class Solution {
public:

    long long countGood(vector<int>& nums, int k) {
        int l=0;
        int r=0;
              unordered_map<int,int>m;
              int n=nums.size();
              long long ans=0;
                long long cnt=0;
            while(r<nums.size())
            {
                    // long long y1=1LL*(m[nums[r]])*(m[nums[r]]-1)/2;
                           m[nums[r]]++;
                        //    long long z1=1LL*(m[nums[r]])*(m[nums[r]]-1)/2;
                             cnt=cnt+ m[nums[r]]-1;
                     while(cnt>=k)
                     {
                        //  cout<<cnt<<" ";
                           ans+=(n-r);
                        //    long long y=1LL*(m[nums[l]])*(m[nums[l]]-1)/2;
                           m[nums[l]]--;
                        //    long long z=1LL*(m[nums[l]])*(m[nums[l]]-1)/2;
                           cnt=cnt-m[nums[l]];
                          
                           l++;
                     }
                     r++;
            }
            return ans;
    }
};