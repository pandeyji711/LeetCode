class Solution {
public:
 vector<vector<int>>dp;
  int solve(vector<vector<int>>& triangle, int r, int i)
  {
                   if(r==triangle.size()-1)
                   {
                       return dp[r][i]=triangle[r][i];
                   }
                   if(dp[r][i]!=-1)return dp[r][i];
                   int x=0;
                   int y=0;
                   x=triangle[r][i]+solve(triangle,r+1,i);
                    y=triangle[r][i]+solve(triangle,r+1,i+1);
                   return dp[r][i]=min(x,y);
  }
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       int m=triangle[triangle.size()-1].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(triangle,0,0);
    }
};