class Solution {
public:
 long long int mod=1e9+7;
  int solve(int low, int high,int one, int zero, int length,vector<int>&dp)
  {

       //add one
                   
                  if(length>high)
                  return 0;
                  if(dp[length]!=-1)
                  return dp[length];
                  int count=0;
                  if(length>=low)
                  count=1;

                  
                    count=(count+solve(low,high,one,zero,length+one,dp))%mod;
                    count=(count+solve(low,high,one,zero,length+zero,dp))%mod;
                 
                  
                    return dp[length] =count;

  }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int>dp(high+2,-1);
    //   int res=solve(low,high,one,zero,0,dp)/2;

        return solve(low,high,one,zero,0,dp);

    }
};