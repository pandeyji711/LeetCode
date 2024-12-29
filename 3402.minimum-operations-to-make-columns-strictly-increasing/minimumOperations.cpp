class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid[0].size();i++)
            {
                  for( int j=1;j<grid.size();j++).
                      {
                             if(grid[j-1][i]>=grid[j][i]){
                            int diff=abs(grid[j-1][i]-grid[j][i]);
                            // int ;
                          ans+=diff+1;
                               grid[j][i]=grid[j][i]+diff+1;  
                             }
                          
                      }
            }
        return ans;
    }
};