class Solution {
public:
  int n;
  int m;
  int dp[101][101];
 int  solve(vector<vector<int>>& ob,int r,int d)
      {    
          if(r>=n||d>=m||ob[d][r]==1)  
          return 0;
          
          if(dp[r][d]!=-1)
           return dp[r][d];
           if(r==n-1&&d==m-1)
                {
                    return 1;
                }
            
                int x=   solve(ob,r+1,d);
           
             
              int y=   solve(ob,r,d+1);
              return dp[r][d]= x+y;
            
      }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
           if(obstacleGrid[0][0]==1)
          return 0;
          memset(dp,-1,sizeof(dp));
        n=obstacleGrid[0].size();
        m=obstacleGrid.size();
        return solve(obstacleGrid,0,0); 
    }
};