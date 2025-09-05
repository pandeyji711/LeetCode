class Solution {
public:
 int solve(vector<int>& obstacles,int l,int ind,  vector<vector<int>>&dp)
 {
              if(ind>=obstacles.size())
              return 0;
              if(dp[ind][l]!=-1)
              return dp[ind][l];
              int a=INT_MAX;
              int index=ind;
              while(index<obstacles.size()&&obstacles[index]!=l)
              {
                   index++;
              }
              if(index>=obstacles.size()) return 0;
              index--;
                       for(int i=1;i<=3;i++)
                       {
                           if(l==i)continue;
                            if(obstacles[index]!=i)
                            {
                                   a=min(a,1+solve(obstacles,i,index,dp));
                            }
                       }

              return  dp[ind][l]= a;
 }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>>dp(obstacles.size()+1,vector<int>(5,-1));
        return solve(obstacles,2,0,dp);
    }
};