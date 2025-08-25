class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
          
          //top
          int n=mat.size();
          int m=mat[0].size();
          vector<int>ans;
          int r=false;
          int ind=0;
          for(int i=0;i<mat.size();i++)
          {   int x=i;
               int y=0;
               while(x>=0&&y<=m-1)
               {
                    ans.push_back(mat[x][y]);
                    x--;
                    y++;
               } 
               if(r)
               {
                   reverse(ans.begin()+ind,ans.end());
                  
               }
                ind=ans.size();
                   r=!r;
                 
          }
          
          //right
          for(int i=1;i<m;i++)
          {   int x=n-1;
               int y=i;
               while(x>=0&&y<=m-1)
               {
                    ans.push_back(mat[x][y]);
                    x--;
                    y++;
               } 
               if(r)
               {
                   reverse(ans.begin()+ind,ans.end());
                  
               }
                ind=ans.size();
                   r=!r;
                 
          }

          return ans;
    }
};
// 1 2 3 4 5
// 1 2 3 3 3
// 6 6 6 6 6