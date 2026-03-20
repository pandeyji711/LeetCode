class Solution {
public:
   int solve(vector<vector<int>>& grid, int k,int i, int j)
   {
                vector<int>v;
                    for(int i1=i;i1<i+k;i1++)
                    {
                           for(int j1=j;j1<j+k;j1++)
                           {
                                 v.push_back(grid[i1][j1]);
                           }
                    }
                    sort(v.begin(),v.end());
                    int minn=INT_MAX;
                    for(int i=0;i<v.size()-1;i++)
                    {
                        // cout<<v[i+1]<<" "<<v[i]<<endl;
                        if(v[i+1]!=v[i])
                      minn=min(minn,abs(v[i+1]-v[i]));
                    }
                    // cout<<"========================"<<endl;
                    return minn==INT_MAX?0:minn;

   }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
              int n=grid.size();
              int m=grid[0].size();
              vector<vector<int>>ans(n-k+1,vector<int>(m-k+1,0));
             for(int i=0;i<grid.size()-k+1;i++)
             {
                  for(int j=0;j<grid[0].size()-k+1;j++)
                  {
                     ans[i][j]=solve(grid,k,i,j);
                  }
             }
             return ans;
    }
};
