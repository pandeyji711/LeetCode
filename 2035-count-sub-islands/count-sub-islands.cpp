class Solution {
public:
  bool  bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>&vis, int x,int y,int n,int m)
  {
                      queue<pair<int,int>>q;
                  q.push({x,y});
                  vis[x][y]=1;
                  bool what=true;
                  while(!q.empty())
                  {
                              int n2=q.size();
                            //   cout<<"k";
                              for(int k=0;k<n2;k++)
                              {
                                     int  i=q.front().first;
                                     int j=q.front().second;
                                       q.pop();
                                       //up
                                       if(i-1>=0&&(grid2[i-1][j]==1)&&vis[i-1][j]==0)
                                       {

                                        // cout<<"k";
                                           if(grid1[i-1][j]==0)what=false;
                                            vis[i-1][j]=1;
                                            q.push({i-1,j});
                                            
                                       }
                                         //down
                                       if(i+1<=n-1&&(grid2[i+1][j]==1)&&vis[i+1][j]==0)
                                       {
                                           if(grid1[i+1][j]==0)what=false;
                                            vis[i+1][j]=1;
                                            q.push({i+1,j});
                                            //  cout<<i<<" "<<j<<endl;
                                       }
                                         //left
                                       if(j-1>=0&&(grid2[i][j-1]==1)&&vis[i][j-1]==0)
                                       {
                                           if(grid1[i][j-1]==0)what=false;
                                            vis[i][j-1]=1;
                                            q.push({i,j-1});
                                       }
                                         //right
                                       if(j+1<=m-1&&(grid2[i][j+1]==1)&&vis[i][j+1]==0)
                                       {
                                           if(grid1[i][j+1]==0)what=false;
                                            vis[i][j+1]=1;
                                            q.push({i,j+1});
                                       }
                              }
                  }
                  return what;
  }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
          int n=grid2.size();
       int m=grid2[0].size();
  vector<vector<int>>vis(n,vector<int>(m,0));
  int ans=0;
    // cout<< bfs(grid1,grid2,vis,0,0,n,m);
             for(int i=0;i<n;i++)
             {
                 for( int j=0;j<m;j++)
                 {
                      if(vis[i][j]==0&&grid2[i][j]==1&&grid1[i][j]==1&&bfs(grid1,grid2,vis,i,j,n,m))
                      {

                        // cout<<"j";
                        // cout<<i<<" "<<j<<endl;

                        ans++;
                      }
                 }
             }
             return ans;
    }
};