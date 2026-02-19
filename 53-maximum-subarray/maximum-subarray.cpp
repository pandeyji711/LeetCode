class Solution {
public:
 int res=INT_MIN;
 int dp[100001];
  int solve(vector<int>&n,int ind)
    { 
        if(ind>=n.size())
        return 0;
        if(dp[ind]!=-1)
         return dp[ind];
         int left=max(n[ind],n[ind]+solve(n,ind+1));
         res=max(res,left);
        return dp[ind]=left ;

    }
    int maxSubArray(vector<int>& nums) {
       memset(dp,-1,sizeof(dp));
       solve(nums,0);
        return res;
    }
};