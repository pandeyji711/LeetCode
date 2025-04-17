class Solution {
public:
  int  bfs(vector<vector<int>>& grid,int x1,int y1)
  {
        queue<pair<int,int>>q;
        q.push({x1,y1});
        grid[x1][y1]=0;
        int ans=1;
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
                              ans++;
                              grid[x-1][y]=0;
                              q.push({x-1,y});
                         }
                         //down
                          if(x+1<grid.size()&&grid[x+1][y]==1)
                         {
                              ans++;
                              grid[x+1][y]=0;
                              q.push({x+1,y});
                         }
                         //left
                          if(y-1>=0&&grid[x][y-1]==1)
                         {
                              ans++;
                              grid[x][y-1]=0;
                              q.push({x,y-1});
                         }
                         //right
                          if(y+1<grid[0].size()&&grid[x][y+1]==1)
                         {
                              ans++;
                              grid[x][y+1]=0;
                              q.push({x,y+1});
                         }
              }
        }
        return ans;
  }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;

         for(int i=0;i<grid.size();i++)
         {
             for( int j=0;j<grid[0].size();j++)
             {
                   if(grid[i][j]==1)
                      ans=max(ans,bfs(grid,i,j));
             }
         }
         return ans;
    }
};