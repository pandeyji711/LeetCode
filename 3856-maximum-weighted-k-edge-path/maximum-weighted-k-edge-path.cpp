class Solution {
public:
   unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;
      int solve(unordered_map<int,vector<pair<int,int>>>&adj,int root,int k,int t,int total)
    {
          
          if(total>=t)
          return INT_MIN;
        if(k==0)
        return dp[root][k][total]= total;

        if(dp[root][k].count(total))return dp[root][k][total];
                  
                     int x=INT_MIN;
                     int y=INT_MIN;
                     for( auto nab:adj[root])
                     {
                            int w=nab.second;
                            
                            int r=nab.first;
                    
                            x=max(x,solve(adj,r,k-1,t,total+w));
                            // cout<<r<<" "<<y<<endl;
                     }
                  
                  return dp[root][k][total]=x;
                   
                   
    }
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++)
            {
                  adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            }
            // vector<int>vis(n,0);//
            int ans=INT_MIN;;
            for(int i=0;i<n;i++)
            {
                        //  memset(dp,-1,sizeof(dp));
                          ans=max(ans,solve(adj,i,k,t,0));
                  
            }
           
            if(ans==0&&k==0)return 0;
            return ans<0?-1:ans;
        
    }
};