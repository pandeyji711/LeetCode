class Solution {
public:
  vector<vector<int>>dp;
  int solve(vector<vector<char>>& matrix,int i,int j,int &maxx)
  {
       if(i>=matrix.size()||j>=matrix[0].size())return 0;
         if(dp[i][j]!=-1)
         return dp[i][j];
       int right=solve(matrix,i,j+1,maxx);
       int down=solve(matrix,i+1,j,maxx);
       int digo=solve(matrix,i+1,j+1,maxx);
        
    //    int ans=0;
        if(matrix[i][j]=='1')
        {
          int   ans=1+min({right,down,digo});
              maxx=max(maxx,ans);
              return dp[i][j]= ans;
        }else
        return  dp[i][j]= 0;

        // return ans;

  }
    int maximalSquare(vector<vector<char>>& matrix) {
       int maxx=0;
       dp.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        solve(matrix,0,0,maxx);
        return maxx*maxx;
    }
};