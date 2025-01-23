class Solution {
public:
int solve(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j)
{
         queue<pair<int,int>>q;
         int cnt=1;
          q.push({i,j});
          vis[i][j]=1;
          while(!q.empty())
          {
                 int n=q.size();
                 for(int m=0;m<n;m++)
                 {

                 
                       int x=q.front().first;
                       int y=q.front().second;
                           q.pop();
                           for(int k=y+1;k<grid[0].size();k++){
                       if(grid[x][k]==1&&vis[x][k]!=1)
                       {
                        cnt++;
                       
                        vis[x][k]=1;
                             q.push({x,k});
                       }
                           }
                         for(int k=y-1;k>=0;k--){
                       if(grid[x][k]==1&&vis[x][k]!=1)
                       {
                        cnt++;
                       
                        vis[x][k]=1;
                             q.push({x,k});
                       }
                           }
                           for(int k=x+1;k<grid.size();k++){
                       if(grid[k][y]==1&&vis[k][y]!=1)
                       {
                          cnt++;
                          vis[k][y]=1;
                          q.push({k,y});

                       }
                           }
                         for(int k=x-1;k>=0;k--){
                       if(grid[k][y]==1&&vis[k][y]!=1)
                       {
                          cnt++;
                          vis[k][y]=1;
                          q.push({k,y});

                       }
                           }
                 }
                //  cout<<cnt<<endl;
          }
          if(cnt==1)
          return 0;
          return cnt;
}
     
    int countServers(vector<vector<int>>& grid) {
        vector<vector<int>>vis(250,vector<int>(250,-1));
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
             for( int j=0;j<grid[0].size();j++)
             {
                  if(grid[i][j]==1&&vis[i][j]==-1)
                  {
                      ans+=solve(grid,vis,i,j);
                  }
             }
        }
        return ans;
    }
};