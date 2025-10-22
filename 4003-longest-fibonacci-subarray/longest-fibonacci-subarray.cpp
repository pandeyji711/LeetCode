class Solution {
public:
 
    int longestSubarray(vector<int>& nums) {
        
        int n1=nums[0];
        int n2=nums[1];
        int ans=2;
        int ind=2;


        while(ind<nums.size())
        {
              int cnt=2;
               while(ind<nums.size()&&n1+n2==nums[ind])
               {
                      cnt++;
                      n1=n2;
                      n2=nums[ind];
                      ind++;
               }
               ans=max(ans,cnt);
                  n1=n2;
                      n2=nums[ind];
                      ind++;
        }
        return ans;
    }
};
// 1 2 3 5 2
