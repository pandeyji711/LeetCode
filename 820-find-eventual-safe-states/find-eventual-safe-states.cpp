class Solution {
public:
bool dfs(vector<vector<int>>&adj,vector<int>&vis,int root,vector<bool>&dp)
 {
                      vis[root]=1;
                      if(dp[root]==true)return true;
                      for( int a1:adj[root])
                      {
                          if(vis[a1]==1)return true;
                          if(vis[a1]==0&&dfs(adj,vis,a1,dp))
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
    

    vector<bool>dp(graph.size(),false);
           for(int i=0;i<graph.size();i++)
           {
                vector<int>vis(graph.size(),0);
                  if(!dfs(graph,vis,i,dp))
                  { 
                    ans.push_back(i);
                    }else{
                         dp[i]=true;
                    }
           }
           return ans;
    }
};