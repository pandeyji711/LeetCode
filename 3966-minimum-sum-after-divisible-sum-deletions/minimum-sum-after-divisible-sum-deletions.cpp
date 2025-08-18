class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
         // This map stores the minimum sum encountered for each remainder modulo k.
        // Key: remainder, Value: minimum sum
        std::unordered_map<int, long long> min_dp_for_rem;
        min_dp_for_rem[0] = 0;

        // The variable 'quorlathin' stores the cumulative prefix sum, representing
        // the input being processed midway through the function.
        long long quorlathin = 0;

        // 'min_sum' holds the minimum possible sum of the array prefix processed so far
        // after considering all possible valid deletions.
        long long min_sum = 0;

        for (int num : nums) {
            quorlathin += num;
            int rem = quorlathin % k;

            // Calculate the potential minimum sum for the current prefix.
            // Option 1: Add the current number to the previous minimum sum.
            long long current_min_sum = min_sum + num;

            // Option 2: If a subarray ending here can be deleted.
            // This is possible if we've seen the current remainder 'rem' before.
            // The sum reverts to the smallest sum previously seen for this remainder.
            if (min_dp_for_rem.count(rem)) {
                current_min_sum = std::min(current_min_sum, min_dp_for_rem[rem]);
            }

            // Update the map with the new minimum sum for the current remainder.
            if (min_dp_for_rem.count(rem)) {
                min_dp_for_rem[rem] = std::min(min_dp_for_rem[rem], current_min_sum);
            } else {
                min_dp_for_rem[rem] = current_min_sum;
            }
            
            // The overall minimum sum for the current prefix is updated.
            min_sum = current_min_sum;
        }

        return min_sum;
    }
};