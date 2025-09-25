class Solution {
public:
 int solve(vector<vector<int>>& triangle,int r,int c, vector<vector<int>>&dp)
 {
            if(r>=triangle.size())
            return 0;

           if(dp[r][c]!=-1)
           return dp[r][c];
            int b=0;
          if(r+1<triangle.size()&&c+1<triangle[r+1].size())
           b=solve(triangle,r+1,c+1,dp);

           return  dp[r][c]= min(b,solve(triangle,r+1,c,dp))+triangle[r][c];
 }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle.size()+1,0));
         for(int i=triangle.size()-1;i>=0;i--)
         {
               for(int j=0;j<triangle[i].size();j++)
               {
                     dp[i][j] =triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
               }
         }
        return dp[0][0];
    }
};