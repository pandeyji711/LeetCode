class Solution {
public:
  long long   bfs(vector<vector<int>>& grid,int x,int y)
  {
                 long long  sum=grid[x][y];
                  queue<pair<int,int>>q;
                     q.push({x,y});
                     grid[x][y]=0;
                     while(!q.empty())
                     {
                          int n=q.size();
                          for(int i=0;i<n;i++)
                          {
                                 int x1=q.front().first;
                                 int y1=q.front().second;
                                 q.pop();
                                 if(x1-1>=0&&grid[x1-1][y1]!=0)
                                 {
                                    q.push({x1-1,y1});
                                    sum+=grid[x1-1][y1];
                                    grid[x1-1][y1]=0;
                                 }
                                  if(x1+1<grid.size()&&grid[x1+1][y1]!=0)
                                 {
                                    q.push({x1+1,y1});
                                    sum+=grid[x1+1][y1];
                                    grid[x1+1][y1]=0;
                                 }
                                  if(y1-1>=0&&grid[x1][y1-1]!=0)
                                 {
                                    q.push({x1,y1-1});
                                    sum+=grid[x1][y1-1];
                                    grid[x1][y1-1]=0;
                                 }
                                  if(y1+1<grid[0].size()&&grid[x1][y1+1]!=0)
                                 {
                                    q.push({x1,y1+1});
                                    sum+=grid[x1][y1+1];
                                    grid[x1][y1+1]=0;
                                 }

                          }
                     }
                     return sum;
  }
    int countIslands(vector<vector<int>>& grid, int k) {
         
        int ans=0;
         for(int i=0;i<grid.size();i++)
         {
              for(int j=0;j<grid[0].size();j++)
              {
                          if(grid[i][j]!=0&&(bfs(grid,i,j)%k==0))
                          {
                            
                                ans++;
                          }
              }
         }
         return ans;
    }
};