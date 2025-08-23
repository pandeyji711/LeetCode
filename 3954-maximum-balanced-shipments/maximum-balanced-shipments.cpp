class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int ans = 0;
        int curMax = weight[0];

        for (int i = 1; i < n; i++) {
            curMax = max(curMax, weight[i]);
            if (weight[i] < curMax) {
               
                ans++;
                if (i+1 < n) curMax = weight[i+1]; 
            }
        }
        return ans;
    }
};
