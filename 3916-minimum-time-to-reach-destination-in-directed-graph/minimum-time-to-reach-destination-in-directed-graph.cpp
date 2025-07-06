class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<int>sc(n,INT_MAX);
           unordered_map<int,vector<vector<int>>>adj;
           for(int i=0;i<edges.size();i++)
           {
                     adj[edges[i][0]].push_back({edges[i][1],edges[i][2],edges[i][3]});
           }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        sc[0]=0;
        while(!pq.empty())
        {
                   int root=pq.top().second;
                   int t=pq.top().first;
                   pq.pop();

                   for(auto &node:adj[root])
                   {
                          
                           if(t<node[1])
                           {
                            //    extime=node[1]-t;
                            // if(node[0]==6)
                                // cout<<node[1]<<" ";
                                    if(sc[node[0]]>node[1]+1)
                                    {
                                         
                                        sc[node[0]]=node[1]+1;
                                        //  if(node[0]==6)
                                        //    cout<<sc[6]<<" ";
                                          pq.push({sc[node[0]],node[0]});
                                    }
                           }else if(t>=node[1]&&t<=node[2])
                           {
                                    if(sc[node[0]]>t+1)
                                    {

                                          
                                        sc[node[0]]=t+1;
                                        //  if(node[0]==6)
                                        //    cout<<sc[6]<<" ";
                                          pq.push({sc[node[0]],node[0]});
                                    }
                           }
                        //    cout<<sc[node[0]]
                   }
        }
        // for(int i=0;i<sc.size();i++)
        // {
        //       cout<<sc[i]<<" ";
        // }
        return sc[n-1]==INT_MAX?-1:sc[n-1];
    }
};