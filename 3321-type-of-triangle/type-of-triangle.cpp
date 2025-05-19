class Solution {
public:
  bool canform(vector<int>& nums)
  {
           int sum=nums[0]+nums[1];
           return sum>nums[2];

  }
    string triangleType(vector<int>& nums) {

        if(nums[0]==nums[1]&&nums[1]==nums[2])return "equilateral";
        sort(nums.begin(),nums.end());
        if(canform(nums)&&nums[0]==nums[1]||nums[1]==nums[2])
        return "isosceles";
        if(canform(nums))
        return "scalene";
        return "none";
    }
};