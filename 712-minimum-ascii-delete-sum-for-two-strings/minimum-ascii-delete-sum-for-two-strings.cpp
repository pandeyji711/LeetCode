class Solution {
public:
 int dp[1001][1001];
  int solve(vector<int>&v1, vector<int>&v2,int ind1,int ind2)
  {
          if(ind1>=v1.size()||ind2>=v2.size())return 0;
          if(dp[ind1][ind2]!=-1)
          return dp[ind1][ind2];
          int a=0;
          int b=0;
          if(v1[ind1]==v2[ind2])
          {
              a=v1[ind1]+solve(v1,v2,ind1+1,ind2+1);
          }
          else{
                b=max(solve(v1,v2,ind1+1,ind2),solve(v1,v2,ind1,ind2+1));
          }
          return dp[ind1][ind2]=max(a,b);
  }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        vector<int>v1,v2;
        int maxx=0;
        for(int i=0;i<s1.length();i++)
        {
             int c1=s1[i];
             maxx+=c1;
             v1.push_back(c1);
        }
         for(int i=0;i<s2.length();i++)
        {
             int c1=s2[i];
             maxx+=c1;
             v2.push_back(c1);
        }
        return maxx-2*solve(v1,v2,0,0);
    }
};
