class Solution {
public:
  int solve(vector<vector<int>>& matrix,int x,int y,int le)
  {
       
             for(int i=x;i<=x+le;i++)
             {
                  for(int j=y;j<=y+le;j++)
                  {
                    //   cout<<i<< " "<<j<<endl;
                        if(matrix[i][j]==0)
                        {
                                     return 0;
                        }
                         
                        
                  }
             }
             return 1;
             

  }
    int countSquares(vector<vector<int>>& matrix) {
        
   int ans=0;
    // cout<<solve(matrix,1,0,1);
    int cnt=0;
         for(int i=0;i<matrix.size();i++)
         {
              for(int j=0;j<matrix[0].size();j++){
            
                if(matrix[i][j]==1)
                {
                     cnt++;
                         
                         int le=min(matrix[0].size()-j-1,matrix.size()-i-1);
                         while(le)
                         {
                            //   cout<<i<< " "<<j<<" "<<le<<endl;
                              ans+=solve(matrix,i,j,le);
                              le--;
                         }

                }
            
              }
         }
         return ans+cnt;
    }
};