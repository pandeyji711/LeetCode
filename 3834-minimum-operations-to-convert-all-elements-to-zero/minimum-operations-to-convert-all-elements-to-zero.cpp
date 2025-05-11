class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                // agar 0 milta hai, positive segment khatam — stack clear karo
                while (!st.empty()) st.pop();
            } else {
                // agar stack.top() > nums[i], wo bada layer is chote element ke saath share nahi ho sakta
                while (!st.empty() && st.top() > nums[i])
                    st.pop();

                // agar stack empty hai ya top < nums[i], toh nums[i] ke liye naya operation layer chahiye
                if (st.empty() || st.top() < nums[i]) {
                    ans++;
                    st.push(nums[i]);
                }
                // agar st.top() == nums[i], toh layer already hai — no new op
            }
        }
        return ans;
    }
};
