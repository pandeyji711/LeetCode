class Solution {
public:
  void bfs(vector<vector<char>>& board, vector<vector<int>>&vis, int x,int y,int n,int m)
  {
                      queue<pair<int,int>>q;
                  q.push({x,y});
                  vis[x][y]=1;

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
                                       if(i-1>=0&&board[i-1][j]=='X'&&vis[i-1][j]==0)
                                       {
                                            vis[i-1][j]=1;
                                            q.push({i-1,j});
                                            
                                       }
                                         //down
                                       if(i+1<=n-1&&board[i+1][j]=='X'&&vis[i+1][j]==0)
                                       {
                                            vis[i+1][j]=1;
                                            q.push({i+1,j});
                                            //  cout<<i<<" "<<j<<endl;
                                       }
                                         //left
                                       if(j-1>=0&&board[i][j-1]=='X'&&vis[i][j-1]==0)
                                       {
                                            vis[i][j-1]=1;
                                            q.push({i,j-1});
                                       }
                                         //right
                                       if(j+1<=m-1&&board[i][j+1]=='X'&&vis[i][j+1]==0)
                                       {
                                            vis[i][j+1]=1;
                                            q.push({i,j+1});
                                       }
                              }
                  }
  }
    int countBattleships(vector<vector<char>>& board) {
       int n=board.size();
       int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        // cout<<n<< " "<<m;
        //  bfs(board,vis,0,3,n,m);
   for(int i=0;i<n;i++)
   {
       for( int j=0;j<m;j++)
       {
            if(board[i][j]=='X'&&vis[i][j]==0)
            { 
               
                bfs(board,vis,i,j,n,m);
                ans++;

            }
       }
   }
        return ans;
    }
};