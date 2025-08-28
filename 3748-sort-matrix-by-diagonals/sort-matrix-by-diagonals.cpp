class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>ans;
        int n=grid.size();
        for(int i=0;i<grid.size();i++)
        {
                int x=i;
                int y=0;
                vector<int>v;
                while(x<n&&y<n)
                {
                      v.push_back(grid[x][y]);
                      x++;
                      y++;
                }
                sort(v.rbegin(),v.rend());
                x=i;
                y=0;
                int ind=0;
                  while(x<n&&y<n)
                {
                     grid[x][y]=v[ind];
                     ind++;
                     x++;
                     y++;
                }
        }
          for(int i=n-1;i>0;i--)
        {
                int x=0;
                int y=i;
                vector<int>v;
                while(x<n&&y<n)
                {
                      v.push_back(grid[x][y]);
                      x++;
                      y++;
                }
                sort(v.begin(),v.end());
                x=0;
                y=i;
                int ind=0;
                  while(x<n&&y<n)
                {
                     grid[x][y]=v[ind];
                     ind++;
                     x++;
                     y++;
                }
        }
        return grid;
    }
};