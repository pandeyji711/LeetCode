class Solution {
public:
  int bfs(unordered_map<int,vector<int>>&adj, vector<int>&vis,int des)
  {
             queue<int>q;
             q.push(0);
             int h=0;
             while(!q.empty())
             {
                int ha=0;
                    int n=q.size();
                    for(int i=0;i<n;i++)
                    {
                           int x=q.front();
                           q.pop();
                           
                           for(int j=0;j<adj[x].size();j++)
                           {
                                if(adj[x][j]==des)
                                {
                                     return h+1;
                                }
                                 if(vis[adj[x][j]]==0)
                                 {
                                    //  if(adj[x][j]==des)
                                    //  {
                                    //     ha=1;
                                    //  }
                                       vis[adj[x][j]] = 1; 
                                        q.push(adj[x][j]);
                                 }
                           }
                    }
                    h++;
                    // if(ha==1)
                    // return h;
             }
             return h;
  }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n-1;i++)
        {
               adj[i].push_back(i+1);
        }
        vector<int>ans;
        vector<int>vis(n,0);
        for(int i=0;i<queries.size();i++)
        {
               adj[queries[i][0]].push_back(queries[i][1]);
              fill(vis.begin(), vis.end(), 0);
               int val=bfs(adj,vis,n-1);
               ans.push_back(val);


        }
        return ans;
    }
};