class Solution {
public:
   void solve(vector<vector<int>>&heights,int x,int y, int &p,int &a)
   {
       int n=heights.size();
       int m=heights[0].size();
                    if(x==0||y==0)
                    {
                          p=1;
                        //  return;
                    }
                    if(x==n-1||y==m-1)
                    {
                         a=1;
                     
                         
                        
                    }
                    if(a&&p)return;
                    heights[x][y]++;
                    if(x-1>=0&&heights[x][y]>heights[x-1][y])
                    {
                             solve(heights,x-1,y,p,a);
                    }
                     if(x+1<=n-1&&heights[x][y]>heights[x+1][y])
                    {
                             solve(heights,x+1,y,p,a);
                    }
                     if(y-1>=0&&heights[x][y]>heights[x][y-1])
                    {
                             solve(heights,x,y-1,p,a);
                    }
                     if(y+1<=m-1&&heights[x][y]>heights[x][y+1])
                    {
                             solve(heights,x,y+1,p,a);
                    }
                    heights[x][y]--;
   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
            vector<vector<int>>ans;
            for(int i=0;i<heights.size();i++)
            {
                  for(int j=0;j<heights[i].size();j++)
                  {
                          int a=0;
                          int p=0;
                          solve(heights,i,j,p,a);
                          if(a&&p)
                          {
                               ans.push_back({i,j});
                          }
                  }
            }
            return ans;
    }
};