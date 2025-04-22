class Solution {
public:
bool dfs(vector<vector<int>>&adj,vector<int>&vis,int root)
 {
                      vis[root]=1;
                      for( int a1:adj[root])
                      {
                          if(vis[a1]==1)return true;
                          if(vis[a1]==0&&dfs(adj,vis,a1))
                          {
                              return true;
                          }
                          
                      }
                  vis[root]=2;
                    //   st.push(root);
                      return false;
 }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int>ans;
  
           for(int i=0;i<graph.size();i++)
           {
                vector<int>vis(graph.size(),0);
                  if(!dfs(graph,vis,i))ans.push_back(i);
           }
           return ans;
    }
};