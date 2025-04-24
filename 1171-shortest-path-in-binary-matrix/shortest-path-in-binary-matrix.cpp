class Solution {
public:
   
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans=1;
        if(grid[0][0]==1)return -1;

          queue<pair<int,int>>q;
          int n1=grid.size();
          q.push({0,0});
        


        // vector<vector<int>>vis(n1,vector<int>(n1,0));
          while(!q.empty())
          {
                 int n=q.size();
                 for(int i=0;i<n;i++)
                 {

                       int x=q.front().first;
                       int y=q.front().second;
                       if(x==n1-1&&y==n1-1)
                       return ans;
                       q.pop();
                    //    up
                       if(x-1>=0&&grid[x-1][y]==0)
                       {
                              grid[x-1][y]=1;
                              q.push({x-1,y});
                       }
                       //down
                         if(x+1<grid.size()&&grid[x+1][y]==0)
                       {
                              grid[x+1][y]=1;
                              q.push({x+1,y});
                       }
                       //left
                         if(y-1>=0&&grid[x][y-1]==0)
                       {
                              grid[x][y-1]=1;
                              q.push({x,y-1});
                       }
                       //right
                         if(y+1<grid.size()&&grid[x][y+1]==0)
                       {
                              grid[x][y+1]=1;
                              q.push({x,y+1});
                       }
                        // topright
                         if(x-1>=0&&y+1<grid.size()&&grid[x-1][y+1]==0)
                       {
                              grid[x-1][y+1]=1;
                              q.push({x-1,y+1});
                       }
                    //    topleft
                         if(x-1>=0&&y-1>=0&&grid[x-1][y-1]==0)
                       {
                              grid[x-1][y-1]=1;
                              q.push({x-1,y-1});
                       }
                    //    bottomleft
                         if(x+1<grid.size()&&y-1>=0&&grid[x+1][y-1]==0)
                       {
                              grid[x+1][y-1]=1;
                              q.push({x+1,y-1});
                       }
                       //bottomright
                         if(x+1<grid.size()&&y+1<grid.size()&&grid[x+1][y+1]==0)
                       {
                              grid[x+1][y+1]=1;
                              q.push({x+1,y+1});
                       }
                 }
                 ans++;

          }
          return -1;
    }
};