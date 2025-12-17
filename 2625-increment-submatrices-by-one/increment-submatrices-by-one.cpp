class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));

        // Apply difference updates
        for (auto &q : queries) {
            int x1 = q[0], y1 = q[1];
            int x2 = q[2], y2 = q[3];

            diff[x1][y1] += 1;
            diff[x2 + 1][y1] -= 1;
            diff[x1][y2 + 1] -= 1;
            diff[x2 + 1][y2 + 1] += 1;
        }

        // Prefix sum row-wise
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        // Prefix sum column-wise
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                diff[i][j] += diff[i - 1][j];
            }
        }

        // Extract final matrix
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = diff[i][j];
            }
        }

        return ans;
    }
};
