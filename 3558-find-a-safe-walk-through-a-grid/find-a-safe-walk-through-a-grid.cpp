class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
       vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
       queue<vector<int>>q;
       q.push({0,0,health-grid[0][0]});
       vis[0][0]=health-grid[0][0];
       int cnt=0;
       while(!q.empty())
       {
            int n=q.size();
              for(int i=0;i<n;i++)
              {
                 int x=q.front()[0];
                 int y=q.front()[1];
                  int h=q.front()[2];
                  q.pop();
                  if(x-1>=0)
                  {
                        if(vis[x-1][y]<h-(grid[x-1][y]==1?1:0))
                        {
                             vis[x-1][y]=h-(grid[x-1][y]==1?1:0);
                             q.push({x-1,y,vis[x-1][y]});
                        
                        }
                  }
                   if(x+1<grid.size())
                  {
                        if(vis[x+1][y]<h-(grid[x+1][y]==1?1:0))
                        {
                             vis[x+1][y]=h-(grid[x+1][y]==1?1:0);
                             q.push({x+1,y,vis[x+1][y]});
                             
                        }
                  }
                   if(y-1>=0)
                  {
                        if(vis[x][y-1]<h-(grid[x][y-1]==1?1:0))
                        {
                             vis[x][y-1]=h-(grid[x][y-1]==1?1:0);
                             q.push({x,y-1,vis[x][y-1]});
                            
                             
                        }
                  }
                   if(y+1<grid[0].size())
                  {
                        if(vis[x][y+1]<h-(grid[x][y+1]==1?1:0))
                        {
                             vis[x][y+1]=h-(grid[x][y+1]==1?1:0);
                             q.push({x,y+1,vis[x][y+1]});
                              
                        }
                  }
              }
       }
  
       return vis[grid.size()-1][grid[0].size()-1]>0?true:false;
    }
};