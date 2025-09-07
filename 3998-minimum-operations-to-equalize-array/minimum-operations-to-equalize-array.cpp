class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]==nums[nums.size()-1])return 0;
        else
        return 1;
    }
};
