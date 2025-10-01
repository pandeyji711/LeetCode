class Solution {
public:
//  int solve(int &n, vector<int>& costs, int ind, vector<int>&dp)
//  {
//             if(ind>=(n-1))
//             {
                 
//                  return 0;
//             }
//             if(dp[ind+1]!=-1)
//             return dp[ind+1];
//             int a=INT_MAX, b =INT_MAX,c=INT_MAX;
//             if(ind+1<=costs.size()-1)
//             {
//                   a=costs[ind+1]+1+solve(n,costs,ind+1,dp);
//             }
//              if(ind+2<=costs.size()-1)
//             {
//                   b=costs[ind+2]+4+solve(n,costs,ind+2,dp);
//             }
//              if(ind+3<=costs.size()-1)
//             {
//                   c=costs[ind+3]+9+solve(n,costs,ind+3,dp);
//             }
            
//             dp[ind+1]=min({a,b,c});
        
//              return  dp[ind+1]=min({a,b,c});

//  }
    int climbStairs(int n, vector<int>& costs) {
        // 
        vector<int>dp(n+2,-1);
        
        vector<int>v(n+3,INT_MAX);
         v[0]=0;
         v[1]=0;
         v[2]=0;
         for(int i=0;i<n;i++)
         {
                v[i+3]=min(v[i+3],v[i]+costs[i]+9);
                v[i+3]=min(v[i+3],v[i+1]+costs[i]+4);
                v[i+3]=min(v[i+3],v[i+2]+costs[i]+1);


         }
         return v[n+2];
        
    }
};