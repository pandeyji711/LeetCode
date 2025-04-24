class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
          int ans=0;
        int ex=entrance[0];
        int ey=entrance[1];
        queue<pair<int,int>>q;
        int n1=maze.size();
        int m1=maze[0].size();
          q.push({ex,ey});
          maze[ex][ey]='+';
          while(!q.empty())
          {
                 int n=q.size();
                 for(int i=0;i<n;i++)
                 {

                       int x=q.front().first;
                       int y=q.front().second;
                       if(x!=ex||y!=ey)
                       {
                             if(x==0||x==n1-1||y==0||y==m1-1)
                             return ans;
                       }
                       q.pop();
                    //    up
                       if(x-1>=0&&maze[x-1][y]=='.')
                       {
                              maze[x-1][y]='+';
                              q.push({x-1,y});
                       }
                       //down
                         if(x+1<maze.size()&&maze[x+1][y]=='.')
                       {
                              maze[x+1][y]='+';
                              q.push({x+1,y});
                       }
                       //left
                         if(y-1>=0&&maze[x][y-1]=='.')
                       {
                              maze[x][y-1]='+';
                              q.push({x,y-1});
                       }
                       //right
                         if(y+1<maze[0].size()&&maze[x][y+1]=='.')
                       {
                              maze[x][y+1]='+';
                              q.push({x,y+1});
                       }
                    
                 }
                 ans++;

          }
          return -1;
    }
};