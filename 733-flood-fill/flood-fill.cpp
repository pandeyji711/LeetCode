class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
  int n1=image.size();
  int n2=image[0].size();
            queue<pair<int,int>>q;
            q.push({sr,sc});
            int col=image[sr][sc];
            image[sr][sc]=color;
            vector<vector<int>>vis(n1,vector<int>(n2,0));
           while(!q.empty())
           {
                    int n=q.size();
                    for(int i=0;i<n;i++)
                    {
                            
                            int x=q.front().first;
                            int y=q.front().second;
                            q.pop();
                            //up
                            if(x-1>=0&&image[x-1][y]==col&&vis[x-1][y]==0)
                            {
                                  image[x-1][y]=color;
                                  q.push({x-1,y});
                                  vis[x-1][y]=1;
                            }
                              //down
                            if(x+1<=n1-1&&image[x+1][y]==col&&vis[x+1][y]==0)
                            {
                                  image[x+1][y]=color;
                                  q.push({x+1,y});
                                  vis[x+1][y]=1;
                            }
                              //left
                            if(y-1>=0&&image[x][y-1]==col&&vis[x][y-1]==0)
                            {
                                  image[x][y-1]=color;
                                  q.push({x,y-1});
                                  vis[x][y-1]=1;
                            }
                              //right
                            if(y+1<=n2&&image[x][y+1]==col&&vis[x][y+1]==0)
                            {
                                  image[x][y+1]=color;
                                  q.push({x,y+1});
                                  vis[x][y+1]=1;
                            }
                    }
           }
           return image;
    }
};