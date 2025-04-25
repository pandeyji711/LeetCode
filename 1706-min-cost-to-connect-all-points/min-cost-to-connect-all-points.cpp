class Solution {
public:
   int dis(vector<int>&p1,vector<int>&p2)
   {
          return abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
   }
    int minCostConnectPoints(vector<vector<int>>& points) {
              unordered_map<int,vector<pair<int,int>>>adj;
              for(int i=0;i<points.size();i++)
              {
                        for(int j=0;j<points.size();j++)
                        {
                                 if(i==j)continue;
                                 adj[i].push_back({j,dis(points[i],points[j])});
                        }
              }
              priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
              pq.push({0,0});
              vector<int>vis(points.size(),0);
              int sum=0;
              while(!pq.empty())
              {
                      int node=pq.top().second;
                      int w=pq.top().first;
                      pq.pop();
                      if(vis[node]==1)continue;
                      vis[node]=1;
                      sum+=w;
                      for(auto a1:adj[node])
                      {
                          if(vis[a1.first]==0)
                          {
                              pq.push({a1.second,a1.first});
                          }
                      }
              }
              return sum;

    }
};