class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int l=x;
        int r=x+k-1;
           while(l<r)
           {
                  for(int i=0;i<k;i++)
                  {
                       swap(grid[l][y+i],grid[r][y+i]);
                  }
                  l++;
                  r--;
           }
           return grid;

    }
};