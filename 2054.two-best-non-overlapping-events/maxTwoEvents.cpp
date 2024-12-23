class Solution {
public:
    // int solve(vector<vector<int>>& events, int ind, int cnt, vector<vector<int>>& dp) {
    //     if (ind >= events.size() || cnt == 2) {
    //         return 0; 
    //     }

    //     if (dp[ind][cnt] != -1)
    //      return dp[ind][cnt]; 

       
    //     int nextInd =lower_bound(events.begin()+ind+1,events.end(),vector<int>{events[ind][1]+1,0,0})-events.begin();
    //     int x = events[ind][2] + solve(events, nextInd, cnt + 1, dp);

    //     int y = solve(events, ind + 1, cnt, dp);

    //     return dp[ind][cnt] = max(x, y); 
    // }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); 
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 0)); 
        for(int i=n-1;i>=0;i--)
        {
                   for(int j=2;j>=1;j--)
                   {
                            int nextInd =lower_bound(events.begin()+i+1,events.end(),          vector<int>{events[i][1]+1,0,0})-events.begin();
                             int x = events[i][2] + dp[nextInd][j-1];

        int y = dp[i+1][j];

                    dp[i][j] = max(x, y);

                   }
        }
        return dp[0][2]; 
    }
};
