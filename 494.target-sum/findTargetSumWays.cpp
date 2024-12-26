class Solution {
public:
  int solve(vector<int>& nums,int target,int sum, int ind,vector<vector<int>>&dp)
  {
                if(ind>=nums.size())
                {
                       if(sum==target)
                       return 1;
                       else
                       return 0;
                }
                 int sum1=sum+1000;
                if(dp[sum1][ind]!=-1)
                return dp[sum1][ind];
                int x=0,y=0;
                x+=solve(nums,target,sum+nums[ind],ind+1,dp);
                y+=solve(nums,target,sum-nums[ind],ind+1,dp);
                return dp[sum1][ind]=x+y;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(2004,vector<int>(21,-1));
        return solve(nums,target,0,0,dp);
    }
};