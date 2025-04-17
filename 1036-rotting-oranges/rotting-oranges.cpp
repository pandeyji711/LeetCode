class Solution {
public:
//  int  bfs(vector<vector<int>>& grid,int x1,int y1)
//   {
//         queue<pair<int,int>>q;
//         q.push({x1,y1});
//         grid[x1][y1]=2;
//         int ans=1;
//         while(!q.empty())
//         {
//               int n=q.size();
//               for(int i=0;i<n;i++)
//               {
//                      int x=q.front().first;
//                      int y=q.front().second;
//                      q.pop();
//                          //up
//                          if(x-1>=0&&grid[x-1][y]==1)
//                          {
//                               ans++;
//                               grid[x-1][y]=0;
//                               q.push({x-1,y});
//                          }
//                          //down
//                           if(x+1<grid.size()&&grid[x+1][y]==1)
//                          {
//                               ans++;
//                               grid[x+1][y]=0;
//                               q.push({x+1,y});
//                          }
//                          //left
//                           if(y-1>=0&&grid[x][y-1]==1)
//                          {
//                               ans++;
//                               grid[x][y-1]=0;
//                               q.push({x,y-1});
//                          }
//                          //right
//                           if(y+1<grid[0].size()&&grid[x][y+1]==1)
//                          {
//                               ans++;
//                               grid[x][y+1]=0;
//                               q.push({x,y+1});
//                          }
//               }
//         }
//         return ans;
//   }
    int orangesRotting(vector<vector<int>>& grid) {
        
        
        
        
         queue<pair<int,int>>q;
         int cnt=0;
           
         for(int i=0;i<grid.size();i++)
         {
             for(int j=0;j<grid[i].size();j++)
             {
                  if(grid[i][j]==0)continue;
                  cnt++;
                    if(grid[i][j]==2)
                    {
                         q.push({i,j});
                           grid[i][j]=2;
                    }

             }
         }
        //  int cnt2=cnt;
        if(q.size()==0&&cnt>0)return -1;
        int ans=0;
        cnt=cnt-q.size();
        // cout<<cnt<<" ";
        while(!q.empty())
        {
              int n=q.size();
              for(int i=0;i<n;i++)
              {
                     int x=q.front().first;
                     int y=q.front().second;
                     q.pop();
                         //up
                         if(x-1>=0&&grid[x-1][y]==1)
                         {
                            //   ans++;
                            cnt--;
                              grid[x-1][y]=2;
                              q.push({x-1,y});
                         }
                         //down
                          if(x+1<grid.size()&&grid[x+1][y]==1)
                         {
                            //   ans++;
                            cnt--;
                              grid[x+1][y]=2;
                              q.push({x+1,y});
                         }
                         //left
                          if(y-1>=0&&grid[x][y-1]==1)
                         {
                            //   ans++;
                            cnt--;
                              grid[x][y-1]=2;
                              q.push({x,y-1});
                         }
                         //right
                          if(y+1<grid[0].size()&&grid[x][y+1]==1)
                         {
                            //   ans++;
                            cnt--;
                              grid[x][y+1]=2;
                              q.push({x,y+1});
                         }
              }
              if(!q.empty())
              ans++;
        }
        return cnt==0?ans:-1;
    }
};