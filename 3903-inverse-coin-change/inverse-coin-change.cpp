class Solution {
public:
   int ways(int n,vector<int>&v,int ind,vector<vector<int>>&dp)
   {
         
         if(n==0)
         return 1;
         if(n<0||ind>=v.size())
         return 0;
         if(dp[n][ind]!=-1)
         return dp[n][ind];
           int x=0;
           int y=0;
           x+=ways(n-v[ind],v,ind,dp);
           y+=ways(n,v,ind+1,dp);

       
         return dp[n][ind]=x+y;
   }
    vector<int> findCoins(vector<int>& numWays) {
        
        vector<int>ans;
        for(int i=0;i<numWays.size();i++)
        {
             vector<vector<int>>dp(i+2,vector<int>(i+1,-1));
                int x=ways(i+1,ans,0,dp);
                if(x==numWays[i])
                continue;
                if(x+1==numWays[i])
                ans.push_back(i+1);
                else{
                    return {};
                }
        }
        return ans;
    }
};