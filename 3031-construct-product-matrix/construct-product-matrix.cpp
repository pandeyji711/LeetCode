class Solution {
public:
 
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int>pro;
        for(int i=0;i<grid.size();i++)
        {
               for(int j=0;j<grid[i].size();j++)
               {
                    // grid[i][j]=grid[i][j]%12345;
                    pro.push_back(grid[i][j]%12345);
               }
            //    cout<<endl;
        }
        int mod=12345;
        vector<int>pre(pro.size()+1,1);
         vector<int>suf(pro.size()+1,1);
         for(int i=0;i<pro.size();i++)
         {
                pre[i+1]=(pre[i]*pro[i])%mod;
         }
           for(int i=pro.size()-1;i>=0;i--)
         {
                suf[i]=(suf[i+1]*pro[i])%mod;
         }
        // cout<<pro;
        vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),0));
       for(int i=0;i<grid.size();i++)
        {
               for(int j=0;j<grid[i].size();j++)
               {
                        int ind=i*grid[0].size()+j;
                        // cout<<ind<<" ";
                        ans[i][j]=(pre[ind]*suf[ind+1])%mod;
               }
        }
        return ans;
    }
};