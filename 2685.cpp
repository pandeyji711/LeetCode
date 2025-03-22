class Solution {
    public:
    vector<int> conponents(unordered_map<int,vector<int>>&adj,vector<int>&vis,int root)
       {
                     queue<int>q;
                     q.push(root);
                     vis[root]=1;
                     vector<int>ans;
                     ans.push_back(root);
                     while(!q.empty())
                     {
                            int n=q.size();
                            for(int i=0;i<n;i++)
                            {
                                      int node=q.front();
                                      q.pop();
                                      for(int n1:adj[node])
                                      {
                                        // cout<<n1<<" ";
                                             if(vis[n1]==0)
                                             {
                                                // cout<<n1<<" ";
                                                q.push(n1);
                                                ans.push_back(n1);
                                                vis[n1]=1;
                                             }
                                      }
                            }
                     }
                    //  cout<</
                     return ans;
    
       }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            unordered_map<int,vector<int>>adj;
            for(int i=0;i<edges.size();i++)
            {
                  
                       adj[edges[i][0]].push_back(edges[i][1]);
                       adj[edges[i][1]].push_back(edges[i][0]);
    
                  
            }
            // cout<<adj[3].size();
            // unoredered_map<int,int>vis;
            vector<int>vis(n,0);
            //  vector<int>nodes=conponents(adj,vis,0);
            //  cout<<nodes.size()<<" ";
    // vector<int>vis(n,0);
    int ans=0;
      for(int i=0;i<n;i++)
      {
            if(vis[i]==0)
            {
                    vector<int>nodes=conponents(adj,vis,i);
                     
                    int numofcom=nodes.size();
                    // cout<<numofcom<<" ";
                    int ha=1;
                     for(int j=0;j<numofcom;j++)
                     {
                         
                              if(adj[nodes[j]].size()!=numofcom-1)
                              {
                                     ha=0;
                                     break;
                              }
                     }
                     if(ha)
                     ans++;
            }
      }
      return ans;
        }
    };