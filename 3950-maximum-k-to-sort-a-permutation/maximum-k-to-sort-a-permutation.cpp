class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int>sor(nums.begin(),nums.end());
        sort(sor.begin(),sor.end()); 
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
                   if(nums[i]!=sor[i])
                   {
                         ans&=nums[i];
                   }
                  
        }
      
        return ans==INT_MAX?0:ans;
        
    }
};