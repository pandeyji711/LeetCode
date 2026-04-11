class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<pair<int,int>>>pre(grid.size(),vector<pair<int,int>>(grid[0].size(),{0,0}));
    int ans=0;
         for(int i=0;i<grid.size();i++)
         {
                   for(int j=0;j<grid[0].size();j++)
                   {
                        pair<int,int>u={0,0},l={0,0},c={0,0};
                          if(i>0)
                          {
                             u=pre[i-1][j];
                          }if(j>0)
                          {
                              l=pre[i][j-1];
                          }
                          if(i>0&&j>0)
                          {
                              c=pre[i-1][j-1];
                          }
                          int x=0;
                          int y=0;
                          if(grid[i][j]=='X')
                          {
                               x=1;
                          }else if(grid[i][j]=='Y')
                          {
                               y=1;
                          }
                        //   int prex=u.first+l.first-c.first+x;
                          pre[i][j]={u.first+l.first-c.first+x,u.second+l.second-c.second+y};
                          if((pre[i][j].first>0||pre[i][j].second>0)&&pre[i][j].first==pre[i][j].second)ans++;
                   }
         }
         return ans;
    }
};

