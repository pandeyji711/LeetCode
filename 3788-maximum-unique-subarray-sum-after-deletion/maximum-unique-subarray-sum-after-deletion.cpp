class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int dub=nums[0];
        int ans=dub;
        for(int i=1;i<nums.size();i++)
        {
               if(nums[i]<0)
               {
                return ans;
               }else if(dub!=nums[i])
               {
                   ans+=nums[i];
                   dub=nums[i];
               }
        }
        return ans;
    }
};