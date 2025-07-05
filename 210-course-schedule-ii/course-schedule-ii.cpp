class Solution {
public: 
    bool iscyc( unordered_map<int,vector<int>>adj,int root,vector<int>&tem,vector<int>&vis)
    {
                             if(vis[root]==1)return true;
                             bool a=false;
                            
                             for(int node:adj[root])
                             {
                                  if(vis[node]==0)
                                  {
                                    a=a||iscyc(adj,node,tem,vis);
                                  }else if(vis[node]==1)
                                  return true;
                             }
                             vis[root]=2;
                              tem.push_back(root);
                             return a;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         if(prerequisites.size()==0)
         {
               vector<int>tem;
               for(int i=0;i<numCourses;i++)
               {
                  tem.push_back(i);
               }
               return tem;
         }
           unordered_map<int,vector<int>>adj;
           vector<int>deg(numCourses,0);
           for(int i=0;i<prerequisites.size();i++)
           {
                   deg[prerequisites[i][0]]++;
                        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
           }
           vector<int>vis(numCourses,0);
              vector<int>tem;
            //   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            //   for(int i=0;i<numCourses;i++)
            //   {
            //         pq.push({deg[i],i});
            //   }
              vector<int>ans;
       
                  
                    for(int i=0;i<numCourses;i++)
                    {

                          if(deg[i]==0)
                          {
                            ans.push_back(i);
                            deg[i]=-1;
                                  for(int node:adj[i])
                                  deg[node]--;

                                    i=-1;
                          }
                        
                    }
           vector<int>tempp;
             return ans.size()==numCourses?ans:tempp;
    }
};