class Solution {
public:
  int dp[10001];
  int solve(vector<int>& nums,int ind)
  {
          if(ind>=nums.size()-1)
          return 0;
          if(dp[ind]!=-1)return dp[ind];
           int x=INT_MAX;
          for(int i=1;i<=nums[ind];i++)
          {
                int tem=solve(nums,ind+i);
                if(tem<INT_MAX)
                  x=min(x,1+tem);
          }
          return  dp[ind]=x;
  }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};