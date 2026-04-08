class Solution {
public:
     long long mod=1e9+7;
     void solve(vector<int>& nums,int l, int r,int k,int v)
    {
               while(l<=r)
                   {
                         nums[l]=((nums[l]%mod)*(v%mod))%mod;
                       l+=k;
                   }
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        for(int i=0;i<queries.size();i++)
            {
                  solve(nums,queries[i][0],queries[i][1],queries[i][2],queries[i][3]);
            }
        int ans=0;
         for(int i=0;i<nums.size();i++)
            {
                  ans=ans^nums[i];
            }
        return ans;
    }
};