class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
           int l=0;
           int n=matrix.size();
           int m=matrix[0].size();
           int r=matrix.size()*matrix[0].size()-1;
           while(l<=r)
           {
              int mid=l+(r-l)/2;
               int x=mid/m;
               int y=mid%m;
               if(matrix[x][y]==target)return true;
               else if(matrix[x][y]>target)
               {
                       r=mid-1;
               }else
               l=mid+1;
           }
           return false;
    }
};