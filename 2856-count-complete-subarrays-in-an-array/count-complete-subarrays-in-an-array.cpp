class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
               m[nums[i]]++;

        }
        int cnt=m.size();
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