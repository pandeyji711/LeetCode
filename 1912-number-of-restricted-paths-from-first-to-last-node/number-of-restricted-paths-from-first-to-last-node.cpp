class Solution {
public:
 long long mod=1e9+7;
 vector<int>dp;
 int solve( unordered_map<int,vector<pair<int,int>>>&adj, vector<int>&vis,int root,int n)
 {
                   if(root==n-1)return 1;
                if(dp[root]!=-1)return dp[root];
                 int x=0;
                   for(auto &a1:adj[root])
                   {
                        if(vis[root]>vis[a1.second])
                             x=(x+solve(adj,vis,a1.second,n))%mod; 
                   }
                   return dp[root]=x%mod;
 }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++)
        {
                  adj[edges[i][0]-1].push_back({edges[i][2],edges[i][1]-1});
                  adj[edges[i][1]-1].push_back({edges[i][2],edges[i][0]-1});
                  
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vis[n-1]=0;
        pq.push({0,n-1});
        while(!pq.empty())
        {
               int node=pq.top().second;
               pq.pop();
               for(auto a1:adj[node])
               {
                           int curr=vis[a1.second];
                           int update=vis[node]+a1.first;
                           if(curr>update)
                           {
                                  vis[a1.second]=update;
                                  pq.push({update,a1.second});
                           }
               }
        }
       dp.resize(n,-1);
        return solve(adj,vis,0,n);
        
    }
};