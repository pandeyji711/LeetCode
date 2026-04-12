class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        unordered_map<int,int>m;
        
        int n=matrix.size();
     
        vector<int>ans(n,0);
        for(int i=0;i<matrix.size();i++)
            {
                 for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1)
                   {
                        // ans[i]++;
                        ans[j]++;
                   }
                 }
            }
       return ans;
    }
};