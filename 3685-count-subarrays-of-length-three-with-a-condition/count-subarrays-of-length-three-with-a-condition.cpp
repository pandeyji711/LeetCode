class Solution {
public:
   
    int countSubarrays(vector<int>& nums) {\
        int ans=0;
          for( int i=0;i<nums.size()-2;i++)
              {
                  //  int x=nums[i];
                  // int y=nums[i+1];
                  // int z=nums[i+2];
                  // float sum=x+z;
                  // y=y/2.0;
                  if((nums[i] + nums[i + 2])==(nums[i + 1] / 2.0))
                      ans++;
              }
        return ans;
    }
};