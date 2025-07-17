class Solution {
public:

    int maximumLength(vector<int>& nums, int k) {
         
         for(int i=0;i<nums.size();i++)
         {
                       nums[i]=nums[i]%k;
         }
         vector<vector<int>>dp(k,vector<int>(k,0));
         int ans=0;
         for(int num:nums)
         {
                int curr=num%k;
                for(int i=0;i<k;i++)
                {
                      dp[i][curr]=dp[curr][i]+1;
                      ans=max(ans,dp[i][curr]);
                }
         }
         return ans;

    }
};