class Solution {
public:
  bool solve( unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>& online,long long &k, long long &mid, int &n )
  {   
    
          priority_queue<pair<long long,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>pq;
          pq.push({0,0});
          vector<long long>sc(n,-1);
          sc[0]=0;
          while(!pq.empty())
          {
                        int root=pq.top().first;
                      long long sum=pq.top().second;
                      pq.pop();
                      if(sc[root]<sum)continue;
                      for(auto  &node:adj[root])
                      {
                            int cost=node.second;
                            int no=node.first;
                            if(cost<mid)
                              continue;
                             if(online[no]&&(sum+cost)<=k&&(sc[no]==-1||sc[no]>=sum+cost))
                             {
                                
                               sc[no]=sum+cost;
                               
                                if(no==n-1)
                                {
                                    return true;
                                }
                                 pq.push({no,sum+cost});
                             }
                      }
                

          }
          return false;
  }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
         int n=edges.size();
          unordered_map<int,vector<pair<int,int>>>adj;
          for(int i=0;i<n;i++)
          {
                 adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
          }
        long long l=0;
          long long r=k+1;
          int n1=online.size();
          long long ans=-1;
          while(l<=r)
          {
                  long long mid=l+(r-l)/2;
                  if(solve(adj,online,k,mid,n1))
                  {
                         ans=mid;
                         l=mid+1;

                  }else
                  r=mid-1;
          }
          return ans;
    }
};