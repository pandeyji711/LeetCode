class Solution {
public:
int getSum(vector<vector<int>>& pre, int r1, int c1, int r2, int c2) {
    int res = pre[r2][c2];
    if (r1 > 0) res -= pre[r1 - 1][c2];
    if (c1 > 0) res -= pre[r2][c1 - 1];
    if (r1 > 0 && c1 > 0) res += pre[r1 - 1][c1 - 1];
    return res;
}
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> pre(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i][j] = mat[i][j];

            if (i > 0) pre[i][j] += pre[i - 1][j];
            if (j > 0) pre[i][j] += pre[i][j - 1];
            if (i > 0 && j > 0) pre[i][j] -= pre[i - 1][j - 1];
        }
    }
        int ans=0;
        for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
                    for(int k=0;k<n&&(j+k<m)&&(i+k<n);k++){
                    int r1=i;
                    int c1=j;
                    int r2=i+k;
                    int c2=j+k;
                    if(getSum(pre,r1,c1,r2,c2)<=threshold&&ans<k+1)
                    {
                          ans=k+1;
                    }


                    }
                      
        }
       
    }
      return ans;   
    }
};

// 1 