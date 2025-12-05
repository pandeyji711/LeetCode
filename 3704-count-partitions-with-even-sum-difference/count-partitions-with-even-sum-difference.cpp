class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int>left(nums.size()+1,0),right(nums.size()+1,0);
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
                left[i+1]=left[i]+nums[i];
        }
         for(int i=nums.size()-1;i>=0;i--)
        {
                right[i]=right[i+1]+nums[i];
        }
        for(int i=0;i<nums.size()-1;i++)
        {
               if(abs(left[i+1]-right[i+1])%2==0)ans++;
        }
        return ans;
    }
};