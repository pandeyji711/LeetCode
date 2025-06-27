class Solution {
public:
  vector<vector<int>>ans;
  void dfs(unordered_map<int,vector<int>>&adj,int root,int cnt,unordered_map<int,pair<int,int>>&mlh,int p)
  {
                  mlh[root]={cnt,cnt};
                //   cout<<root<<" "<<cnt<<endl;
                   for(int node:adj[root])
                   {
                        if(node==p)continue;
                         if(mlh.find(node)==mlh.end())
                         {  
                              dfs(adj,node,cnt+1,mlh,root);
                               mlh[root].second=min(mlh[root].second,mlh[node].second);
                                     if(mlh[root].first<mlh[node].second)
                         {
                                         ans.push_back({node,root});
                         }
                         }
                        else{
                          mlh[root].second=min(mlh[root].second,mlh[node].first);
                        }
                         
                         
                         
                   }
  }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<connections.size();i++)
        {
                 adj[connections[i][0]].push_back(connections[i][1]);
                 adj[connections[i][1]].push_back(connections[i][0]);

        }
        unordered_map<int,pair<int,int>>mlh;
        dfs(adj,0,0,mlh,-1);
        return ans;
    }
};