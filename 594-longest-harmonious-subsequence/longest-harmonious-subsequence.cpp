class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=0;
       int  ans=0;
        while(r<nums.size())
        {
            // cout<<r<<" ";
               while(l>=0&&nums[r]-nums[l]>1)
               {
                //  cout<<l<<" ";
                    l++;
               }
               if(nums[r]-nums[l]==1)
               ans=max(ans,r-l+1);
               r++;
        }
        return ans;
    }
};