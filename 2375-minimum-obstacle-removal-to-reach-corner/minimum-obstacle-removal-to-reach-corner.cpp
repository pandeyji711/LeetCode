class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
       int m=grid[0].size();
        int x=n-1;
        int y=m-1;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>cost(n,vector<int>(m,INT_MAX));
        pq.push({0,x,y});
        cost[x][y]=0;
        while(!pq.empty())
        {
              int x1=pq.top()[1];
              int y1=pq.top()[2];
              pq.pop();
              //up
              if(x1-1>=0)
              {
                     int pre=cost[x1-1][y1];
                       int curr=((grid[x1-1][y1]==0)?0:1)+cost[x1][y1];
                       if(pre>curr)
                       {
                           cost[x1-1][y1]=curr;
                           pq.push({curr,x1-1,y1});
                       }
              }
              //left
              if(y1-1>=0)
              {
                     int pre=cost[x1][y1-1];

                       int curr=((grid[x1][y1-1]==0)?0:1)+cost[x1][y1];
                       if(pre>curr)
                       {
                           cost[x1][y1-1]=curr;
                           pq.push({curr,x1,y1-1});
                       }
              }
              //right
              if(y1+1<m)
              {
                     int pre=cost[x1][y1+1];
                       int curr=((grid[x1][y1+1]==0)?0:1)+cost[x1][y1];
                       if(pre>curr)
                       {
                           cost[x1][y1+1]=curr;
                           pq.push({curr,x1,y1+1});
                       }
              }
              //down
              if(x1+1<n)
              {
                     int pre=cost[x1+1][y1];
                       int curr=((grid[x1+1][y1]==0)?0:1)+cost[x1][y1];
                       if(pre>curr)
                       {
                           cost[x1+1][y1]=curr;
                           pq.push({curr,x1+1,y1});
                       }
              }
            //    for(int i=0;i<n;i++)
            //    {
            //   for(int j=0;j<m;j++)
            //   {
            //      cout<<cost[i][j]<<" ";

            //   }
            //   cout<<endl;
            //   }
            //   cout<<"=================================================="<<endl;
        }
      
        return cost[0][0];
    }
};