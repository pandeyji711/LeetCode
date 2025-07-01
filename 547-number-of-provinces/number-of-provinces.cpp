class Solution {
public:
    void bfs( unordered_map<int,vector<int>>adj,vector<int>&vis,int root)
    {
            queue<int>q;
            q.push(root);
            vis[root]=1;
            while(!q.empty())
            {
                  int  n=q.size();
                  for(int i=0;i<n;i++)
                  {
                         int node=q.front();
                         q.pop();
                         for(int x:adj[node])
                         {
                              if(vis[x]==0)
                              {
                                    q.push(x);
                                    vis[x]=1;
                              }
                         }
                  }
            }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         unordered_map<int,vector<int>>adj;
         for(int i=0;i<isConnected.size();i++)
         {
                  int root=i;
                  for(int j=0;j<isConnected.size();j++)
                  {
                        if(i==j)continue;
                        if(isConnected[i][j]==1)
                        {
                               adj[root].push_back(j);
                        }
                  }
         }
         int n=isConnected.size();
         vector<int>vis(n,0);
         int ans=0;
         for(int i=0;i<n;i++)
         {
              if(vis[i]==0)
              {
                  bfs(adj,vis,i);
                  ans++;
              }
         }
         return ans;
    }
};