class Solution {
public:
    bool bfs(vector<vector<int>>& heights,int x,int y, vector<vector<int>>&dp, vector<vector<int>>&vis)
    {
          if(dp[x][y]==1)return true;
             queue<pair<int,int>>q;
             int n=heights.size();
             int m=heights[0].size();
             q.push({x,y});
            //  vector<vector<int>>vis(heights.size(),vector<int>(m,0));
             bool p=false;
             bool a=false;
              if(x==0||y==0)
              p=true;
              if(y==m-1||x==n-1)
              a=true;
              vis[x][y]=1;
             while(!q.empty())
             {
                    int n2=q.size();
                    for(int i=0;i<n2;i++)
                    {
                           int x1=q.front().first;
                           int y1=q.front().second;
                           //up
                           q.pop();
                           if(x1-1>=0&&vis[x1-1][y1]==0&&heights[x1][y1]>=heights[x1-1][y1])
                           {
                                  if(dp[x1-1][y1]==1)return true;
                                 if(x1-1==0||y1==0)
                                   p=true;
                                  if(y1==m-1||x1-1==n-1)
                                    a=true;
                                    q.push({x1-1,y1});
                                    vis[x1-1][y1]=1;
                           }
                             //down
                           if(x1+1<n&&vis[x1+1][y1]==0&&heights[x1][y1]>=heights[x1+1][y1])
                           {
                               if(dp[x1+1][y1]==1)return true;
                                 if(x1+1==0||y1==0)
                                   p=true;
                                  if(y1==m-1||x1+1==n-1)
                                    a=true;
                                    q.push({x1+1,y1});
                                     vis[x1+1][y1]=1;
                           }
                             //left
                           if(y1-1>=0&&vis[x1][y1-1]==0&&heights[x1][y1]>=heights[x1][y1-1])
                           {
                             if(dp[x1][y1-1]==1)return true;
                                 if(x1==0||y1-1==0)
                                   p=true;
                                  if(y1-1==m-1||x1==n-1)
                                    a=true;
                                    q.push({x1,y1-1});
                                     vis[x1][y1-1]=1;
                           }
                             //right
                           if(y1+1<m&&vis[x1][y1+1]==0&&heights[x1][y1]>=heights[x1][y1+1])
                           {
                             if(dp[x1][y1+1]==1)return true;
                                 if(x1==0||y1+1==0)
                                   p=true;
                                  if(y1+1==m-1||x1==n-1)
                                    a=true;
                                    q.push({x1,y1+1});
                                     vis[x1][y1+1]=1;
                           }
                           
                    }
             }
             return p&&a;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
             vector<vector<int>>ans;
             vector<vector<int>>dp(heights.size()+1,vector<int>(heights[0].size()+1,0));
              vector<vector<int>>vis(heights.size(),vector<int>(heights[0].size(),0));
               for(int i=0;i<heights.size();i++)
               {
                  for(int j=0;j<heights[0].size();j++)
                  {
                       
                          for (auto &row : vis) fill(row.begin(), row.end(), 0);
                               if(bfs(heights,i,j,dp,vis)){
                               ans.push_back({i,j});
                               dp[i][j]=1;
                               }
                  }
               }
               return ans;
    }
};