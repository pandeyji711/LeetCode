class Solution {
public:
    
    long long maxSubarraySum(vector<int>& nums, int k) {
        
            int n = nums.size();
    vector<long long> minPref(k, LLONG_MAX);

    long long prefix = 0;
    long long ans = LLONG_MIN;

    minPref[0] = 0;  // prefix sum at index -1

    for (int i = 0; i < n; i++) {
        prefix += nums[i];

        int r = (i + 1) % k;

        if (minPref[r] != LLONG_MAX) {
            ans = max(ans, prefix - minPref[r]);
        }

        // update minimum prefix sum for this remainder class
        minPref[r] = min(minPref[r], prefix);
    }

    return ans;
    }
};