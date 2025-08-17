class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
         unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++)
            {
                  adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
                  adj[edges[i][1]].push_back({edges[i][0],2*edges[i][2]});
                
            }
          vector<int>sc(n,INT_MAX);
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
           sc[0]=0;
          pq.push({0,0});
        // sc[0]=0;
        while(!pq.empty())
            {
                    int node=pq.top().second;
                    
                    pq.pop();
                    for(auto &x:adj[node])
                        {
                              long long  tem=(long long )sc[node]+(long long )abs(x.second);
                               if(tem<sc[x.first])
                               {
                                     sc[x.first]=tem;
                                     pq.push({sc[x.first],x.first});
                               }
                            
                        }
            }
       return  sc[n-1]==INT_MAX?-1:sc[n-1];
         
    }
};