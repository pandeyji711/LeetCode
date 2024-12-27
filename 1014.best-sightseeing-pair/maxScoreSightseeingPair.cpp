class Solution {
public:
 int solve(vector<int>& values,int ind , int cnt, vector<vector<int>>&dp)
 {
              if(ind>=values.size())
              {
                  if(cnt<=0)
                  return 0;
                  else
                  return INT_MIN;
              }
              else if(cnt<=0)
              {
                  return 0;
              }
              if(dp[ind][cnt]!=-1)
              return dp[ind][cnt];
              //pick
              int x=0;
              if(cnt==2)
              x=(values[ind]+ind)+solve(values,ind+1,cnt-1,dp);
              else if(cnt==1)
              x=(values[ind]-ind)+solve(values,ind+1,cnt-1,dp);
             int y=solve(values,ind+1,cnt,dp);
              return  dp[ind][cnt]= max(x,y);
 }
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return solve(values,0,2,dp);
    }
};