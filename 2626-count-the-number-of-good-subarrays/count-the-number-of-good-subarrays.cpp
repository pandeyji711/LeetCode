class Solution {
public:
  bool ch( unordered_map<int,int>&m,int k)
  {
           long long cnt=0;
           for( auto a1:m)
           {
                 int x=a1.second;
                 cnt+=(x)*(x-1)/2;
                 if(cnt>=k)return 1;
           }
           return cnt>=k;

  }
    long long countGood(vector<int>& nums, int k) {
        int l=0;
        int r=0;
              unordered_map<int,int>m;
              int n=nums.size();
              long long ans=0;
                long long cnt=0;
            while(r<nums.size())
            {
                    long long y1=1LL*(m[nums[r]])*(m[nums[r]]-1)/2;
                           m[nums[r]]++;
                           long long z1=1LL*(m[nums[r]])*(m[nums[r]]-1)/2;
                             cnt=cnt+abs(y1-z1);
                     while(cnt>=k)
                     {
                        //  cout<<cnt<<" ";
                           ans+=(n-r);
                           long long y=1LL*(m[nums[l]])*(m[nums[l]]-1)/2;
                           m[nums[l]]--;
                           long long z=1LL*(m[nums[l]])*(m[nums[l]]-1)/2;
                           cnt=cnt-abs(y-z);
                          
                           l++;
                     }
                     r++;
            }
            return ans;
    }
};