class Solution {
public:
//   vector<vector<int>>dp;
//   int solve(vector<vector<char>>& matrix,int i,int j,int &maxx)
//   {
//        if(i>=matrix.size()||j>=matrix[0].size())return 0;
//          if(dp[i][j]!=-1)
//          return dp[i][j];
//        int right=solve(matrix,i,j+1,maxx);
//        int down=solve(matrix,i+1,j,maxx);
//        int digo=solve(matrix,i+1,j+1,maxx);
        
//     //    int ans=0;
//         if(matrix[i][j]=='1')
//         {
//           int   ans=1+min({right,down,digo});
//               maxx=max(maxx,ans);
//               return dp[i][j]= ans;
//         }else
//         return  dp[i][j]= 0;

//         // return ans;

//   }
    int maximalSquare(vector<vector<char>>& matrix) {
     
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
    //    dp.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
    //  int maxx=0;
      int maxx=0;
       for(int i=0;i<matrix.size();i++)
       {
                  for(int j=0;j<matrix[0].size();j++)
                  {
                           if(matrix[i][j]=='1')
                           {
                                 dp[i+1][j+1]=1+min({dp[i][j],dp[i+1][j],dp[i][j+1]});
                                  maxx=max(maxx,dp[i+1][j+1]);
                           }else
                           dp[i+1][j+1]=0;
                  }
       }
        // solve(matrix,0,0,maxx);
        return maxx*maxx;
    }
};