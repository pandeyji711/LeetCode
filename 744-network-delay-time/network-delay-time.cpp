class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>vis(n,INT_MAX);
         vector<vector<pair<int, int>>> adj(n + 1); // 1-indexed
        for (auto& t : times) {
            adj[t[0]].emplace_back(t[2], t[1]); // u -> (v, weight)
        }


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,k});
        vis[k-1]=0;
    int ans=INT_MIN;
        while(!pq.empty())
        {
                  int node=pq.top().second;
                 pq.pop();
                  for( auto a1:adj[node])
                  {
                        int curr=vis[a1.second-1];
                        int  update=vis[node-1]+a1.first;
                        if(curr>update)
                        {
                               vis[a1.second-1]=update;
                               pq.push({update,a1.second});
                        }
                  }
                //   if(!pq.empty())

                  
        }
        for(int i=0;i<vis.size();i++)
        {
             ans=max(ans,vis[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};