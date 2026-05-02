class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f0=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
              f0+=i*nums[i];
              sum+=nums[i];
        }
      int  pre=f0;
      int ans=f0;
      int n=nums.size();
      for(int i=1;i<nums.size();i++)
      {
              int curr=pre+sum-(n)*nums[n-i];
              ans=max(curr,ans);
              pre=curr;
      }
      return ans;
    }
};