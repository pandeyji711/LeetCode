class Solution {
public:
long long const mod= 1e9+7;
int dp[301][301];
vector<long long>p;
  int solve(int n, int &x,int ind)
  {
          if(n==0)
          return dp[n][ind]=1;
          if(n<0)
          return 0;
          if(dp[n][ind]!=-1)
          return dp[n][ind];

          int a=0;
          for(int i=ind;i<p.size();i++)
          {

                 long long tem=p[i];

                 if(tem>n)
                 break;

             a=(a%mod+solve(n-p[i],x,i+1)%mod)%mod;
          }
          return dp[n][ind]=a;
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