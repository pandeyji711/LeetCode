class Solution {
public:
  int dp[201][20001];
    bool solve(vector<int>& nums,int ind,int sum,int &total)
    {
               
               if(ind>=nums.size())return false;
               if(sum==total)
               return true;
               if(dp[ind][sum]!=-1)
               return dp[ind][sum];
                 //take
                 bool x=false;
                 bool y=false;
                 x=x|solve(nums,ind+1,sum+nums[ind],total);
                 y=y|solve(nums,ind+1,sum,total);
                 return dp[ind][sum]=x|y;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        memset(dp,-1,sizeof(dp));
        if(sum%2!=0)return false;
        int t=sum/2;
        
        return solve(nums,0,0,t);
    }
};