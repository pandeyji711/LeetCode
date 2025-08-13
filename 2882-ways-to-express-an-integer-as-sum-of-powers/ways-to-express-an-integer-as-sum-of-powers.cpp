class Solution {
public:
long long const mod= 1e9+7;
int dp[301][301];
vector<long long>p;
  int solve(int n, int &x,int ind)
  {
          if(n==0)
          return dp[n][ind]=1;
          if(n<0||ind>=p.size())
          return 0;
          if(dp[n][ind]!=-1)
          return dp[n][ind];

          int a=0;
          int b=0;
          a=solve(n-p[ind],x,ind+1);
          b=solve(n,x,ind+1);
          return dp[n][ind]=(a%mod+b%mod)%mod;
  }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        for(int i=1;pow(i,x)<=n;i++)
        {
            p.push_back((long long )pow(i,x));
        }
        return solve(n,x,0);
    }
};