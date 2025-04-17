class Solution {
public:
  int solve( unordered_map<int,vector<pair<int,int>>>&adj,int src, int dst, int k,int n){
   k++;
     vector<int>best(n,INT_MAX);
      int ans=INT_MAX;
       vector<int>tembest(n,INT_MAX);
                  queue<int>q;
                  q.push(src);
                  best[src]=0;
                  tembest=best;
                  while(!q.empty()&&k>0)
                  {
                          int n=q.size();
                    
                          for(int i=0;i<n;i++)
                          {
                                int ele=q.front();
                                q.pop();
                                for( auto a1:adj[ele])
                                {
                                      
                                      int costi=a1.second;
                                      if(tembest[a1.first]>costi+tembest[ele])
                                      {
                                        q.push(a1.first);
                                      }
                                      tembest[a1.first]=min(tembest[a1.first],costi+best[ele]);
                                      if(a1.first==dst)
                                      {
                                           
                                           ans=min(ans,costi+best[ele]);
                                      } 
                                     

                                }
                                 
                          }
                          best=tembest;
                         
                          k--;
                  }
                  return ans==INT_MAX?-1:ans;

  }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
    //  map<pair<int,int>,int>cost;
        for(int i=0;i<flights.size();i++)
        {
                 adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
                //  cost[{flights[i][0],flights[i][1]}]=flights[i][2];
        }
        return solve(adj,src,dst, k,n);
    }
};