class Solution {
public:
   bool solve(unordered_map<int,vector<int>>&adj,int root,int col,vector<int>&vis)
   {
        
               if(vis[root]!=-1&&col!=vis[root])return false;
               vis[root]=col;
            //    cout<<col<<" ";
               bool x=true;
                 for(int node:adj[root])
                 {
                         if(vis[node]==-1)
                         {
                            x=x&&solve(adj,node,!col,vis);
                         }
                      
                         else if(vis[node]!=-1&&vis[node]!=!col)
                         {
                            return false;
                         }

                 }

                 return x;
   }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
           
            unordered_map<int,vector<int>>adj;
            for(int i=0;i<dislikes.size();i++)
            {
                   adj[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
                    adj[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
            }
            vector<int>vis(n,-1);
            bool ans=true;
            for(int i=0;i<n;i++)
            {
                   if(vis[i]==-1)
                    ans=ans&&solve(adj,i,0,vis);
            }
            return ans;
    }
};