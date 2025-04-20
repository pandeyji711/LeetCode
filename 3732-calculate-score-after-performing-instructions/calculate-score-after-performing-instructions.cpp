class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        unordered_map<int, int> m; 
        long long ans = 0;
        int ind = 0;

        while (ind >= 0 && ind < instructions.size()) {
            if (m[ind] > 0) break; 
            m[ind]++; 

            if (instructions[ind] == "jump") {
                ind += values[ind]; 
            } 
            else {
                ans += values[ind]; 
                ind++; 
            }
        }

        return ans;
    }
};
