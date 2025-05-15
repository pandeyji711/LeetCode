class Solution {
public:
   int solve(string &s, int ind,int al,int k,  vector<vector<int>>&dp)
   {
             if(ind>=s.length())
             return 0;
             if(dp[ind][al+1]!=-1)
             return dp[ind][al+1];
             int x=0;
             int y=0;
             int tem=(s[ind]-'a');
              int diff=abs(tem-al);
             if(al==-1||diff<=k)
             x=1+solve(s,ind+1,tem,k,dp);
             y=solve(s,ind+1,al,k,dp);
             return dp[ind][al+1]=max(x,y);
   }
    int longestIdealString(string s, int k) {
        vector<vector<int>>dp(s.length()+1,vector<int>(28,-1));
        return solve(s,0,-1,k,dp);
    }
};