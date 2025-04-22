class Solution {
public:
int  dfs(vector<vector<int>>&adj,vector<int>&vis,int root)
 {
                      
                      if(vis[root]!=0)return vis[root];
                      vis[root]=1;
                    //   if(dp[root]==true)return true;
                      for( int a1:adj[root])
                      {
    
                          if(dfs(adj,vis,a1)==1)
                          {
                              return 1;
                          }
                          
                      }
                 
                    //   st.push(root);
                      return  vis[root]=2;
 }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int>ans;
    

    // vector<bool>dp(graph.size(),false);
     vector<int>vis(graph.size(),0);
           for(int i=0;i<graph.size();i++)
           {
               
                  if(dfs(graph,vis,i)==2)
                  { 
                    ans.push_back(i);
                    }
           }
           return ans;
    }
};