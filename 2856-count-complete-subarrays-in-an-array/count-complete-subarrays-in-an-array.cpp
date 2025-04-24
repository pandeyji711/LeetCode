class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        vector<int>m(2001,0);
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
               m[nums[i]]++;
               if(m[nums[i]]==1)cnt++;

        }
        int n=nums.size();
          vector<int>cn(2001,0);
          int l=0;
          int r=0;
          int ans=0;
          while(r<n)
          {
                 cn[nums[r]]++;
                 if(cn[nums[r]]==1)
                 cnt--;
                 while(cnt==0)
                 {
                       ans+=n-r;
                       cn[nums[l]]--;
                       if(cn[nums[l]]==0)
                       cnt++;
                       l++;
                 }
                 r++;
          }
          return ans;

    }
};