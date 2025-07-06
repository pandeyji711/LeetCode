class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>>sc(m,vector<long long >(n,LLONG_MAX));
        priority_queue<vector<long long >,vector<vector<long long>>,greater<vector<long long >>>pq;
        pq.push({1,0,0});
        sc[0][0]=1;
       while(!pq.empty())
       {
                int x=pq.top()[1];
                int y=pq.top()[2];
                pq.pop();
                //right
                if(y+1<n)
                {
                      long long  wait=1LL*waitCost[x][y+1];
                      long long  cost=1LL*(x+1)*(y+2);
                       if(sc[x][y]+wait+cost<sc[x][y+1])
                       {
                          if(x==m-1&&y+1==n-1)
                          {
                              sc[x][y+1]=sc[x][y]+cost;
                          }else
                         sc[x][y+1]=sc[x][y]+wait+cost;
                           pq.push({sc[x][y+1],x,y+1});
                       }
                }
                //down
                if(x+1<m)
                {
                      long long  wait=1LL*waitCost[x+1][y];
                      long long  cost=1LL*(x+2)*(y+1);
                       if(sc[x][y]+wait+cost<sc[x+1][y])
                       {
                         if(x+1==m-1&&y==n-1)
                          {
                              sc[x+1][y]=sc[x][y]+cost;
                          }else
                         sc[x+1][y]=sc[x][y]+wait+cost;
                           pq.push({sc[x+1][y],x+1,y});
                       }
                }

       }
       return sc[m-1][n-1];
    }
};