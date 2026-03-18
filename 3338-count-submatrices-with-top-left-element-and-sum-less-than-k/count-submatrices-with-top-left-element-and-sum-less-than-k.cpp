class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>>pre(grid.size(),vector<int>(grid[0].size(),0));
 int ans=0;
        for(int i=0;i<grid.size();i++)
        {
             for(int j=0;j<grid[0].size();j++)
             {
                   if(i>0)
                   pre[i][j]+=pre[i-1][j];
                   if(j>0)
                   pre[i][j]+=pre[i][j-1];
                   pre[i][j]+=grid[i][j];
                   if(i>0&&j>0)
                   pre[i][j]-=pre[i-1][j-1];
               
                   if(pre[i][j]>k)break;
                   ans++;
             }
             
        }
        return ans;
    }
};