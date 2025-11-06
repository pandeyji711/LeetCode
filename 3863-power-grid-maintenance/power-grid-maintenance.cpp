class Solution {
public:
 void dfs(unordered_map<int,vector<int>>&adj,vector<int>&vis,int root,unordered_map<int,int>&com,int &c, unordered_map<int,priority_queue<int,vector<int>,greater<int>>>&compq)
 {
               vis[root]=1;
               com[root]=c;
               compq[c].push(root);
               for(int node:adj[root])
               {
                        if(!vis[node])
                        {
                              dfs(adj,vis,node,com,c,compq);
                        }
               }
 }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
           unordered_map<int,vector<int>>adj;
           for(int i=0;i<connections.size();i++)
           {
                         adj[connections[i][0]].push_back(connections[i][1]);
                         adj[connections[i][1]].push_back(connections[i][0]);

           }
           vector<int>vis(c+1,0);
           unordered_map<int,int>com;
           unordered_map<int,priority_queue<int,vector<int>,greater<int>>>compq;
           int comp=1;
           for(int i=1;i<=c;i++)
           {
                  if(!vis[i])
                  {
                      dfs(adj,vis,i,com,comp,compq);
                      comp++;
                  }
           }
          vector<int>online(c+1,1);
          vector<int>ans;
           for(int i=0;i<queries.size();i++)
           {
                    if(queries[i][0]==2)
                    {
                          online[queries[i][1]]=0;
                         

                    }else{
                            if(online[queries[i][1]]==1)
                            {
                                 ans.push_back(queries[i][1]);
                            }else{
                                    
                                    auto &pq=compq[com[queries[i][1]]];
                                    while(!pq.empty()&&online[pq.top()]==0)pq.pop();
                                    if(pq.empty())
                                    ans.push_back(-1);
                                    else{
                                        ans.push_back(pq.top());
                                    }
                            }
                    }
           }
           return ans;




    }
};