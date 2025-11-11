class Solution {
public:
int dp[601][101][101];
  int solve(vector<pair<int,int>>&v,int ind, int n, int m)
  {
                   if(ind>=v.size())return 0;
                   if(dp[ind][n][m]!=-1)
                   return dp[ind][n][m];
                     int x=0;
                     if(v[ind].first<=n&&v[ind].second<=m)
                     {
                             x=1+solve(v,ind+1,n-v[ind].first,m-v[ind].second);
                     }
                     int y=solve(v,ind+1,n,m);
                     return  dp[ind][n][m]=max(x,y);
  }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>v;
        for(int i=0;i<strs.size();i++)
        {
             int cnt1=0;
             int cnt0=0;
                for(char c:strs[i])
                {
                      if(c=='0')
                      {
                        cnt1++;
                      }else{
                        cnt0++;
                      }
                }
                v.push_back({cnt0,cnt1});
        }
        memset(dp,-1,sizeof(dp));

        return solve(v,0,n,m);
        
      
    }
};