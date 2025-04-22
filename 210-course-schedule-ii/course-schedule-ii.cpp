class Solution {
public:
stack<int>st;
 
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
                      st.push(root);
                      return false;
 }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
  vector<vector<int>>adj(numCourses);
   vector<int>deg(numCourses,0);
    for(int i=0;i<prerequisites.size();i++)
    {
                adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
                // deg[prerequisites[i][1]]++;
    }
    // bool yes=false;
    //  for(int i=0;i<deg.size();i++)
    //  {
    //            if(deg[i]==0){
    //               yes=true;
    //               break;
    //            }
    //  }
    //  if(!yes)return {};
          vector<int>vis(numCourses,0);

          for(int i=0;i<numCourses;i++)
          {
                    if(vis[i]==0)
                    {
                         if(dfs(adj,vis,i))
                         return {};
                    }
          }
          vector<int>ans;
          while(!st.empty())
          {
                 ans.push_back(st.top());
                 st.pop();
          }
          reverse(ans.begin(),ans.end());
          return ans;
    }
};