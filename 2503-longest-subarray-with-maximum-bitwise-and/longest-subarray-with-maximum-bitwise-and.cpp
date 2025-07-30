class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxx=0;
        for(int i=0;i<nums.size();i++)
        {
              maxx=max(maxx,nums[i]);
        }
        int dub=maxx;
        int le=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
               if(dub!=nums[i])
               {
                    ans=max(ans,le);
                    le=0;
               }else{
                   le++;
               }
        }
         ans=max(ans,le);
         return ans;
    }
};