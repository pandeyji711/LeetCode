class Solution {
public:

  pair<long long,long long> solve(vector<int>& nums,int ind, vector<pair<long long,long long>>&dp)
  {
          if(ind>=nums.size()-1)return {0,0};
          if(dp[ind].first!=-1&&dp[ind].second!=-1)return dp[ind];
          pair<long long ,long long> a={0,0};
          pair<long long ,long long> b={0,0};
          if(nums[ind]>nums[ind-1]&&nums[ind]>nums[ind+1])
          {
                pair<int,long long> tem=solve(nums,ind+2,dp);
                a={tem.first+1,tem.second};
          }else{
                  int inc=(max(nums[ind-1],nums[ind+1])+1)-nums[ind];
                  pair<long long ,long long> tem1=solve(nums,ind+2,dp);
                  pair<long long ,long long> tem2={tem1.first+1,tem1.second+inc};
                   pair<long long ,long long> tem3=solve(nums,ind+1,dp);
                   if(tem3.first>tem2.first)
                   b=tem3;
                   else if(tem3.first<tem2.first)
                   b=tem2;
                   else if(tem3.first==tem2.first)
                   {
                         if(tem3.second<tem2.second)
                         b=tem3;
                         else
                         b=tem2;
                   }
          }
          pair<long long ,long long> ans;
           if(a.first>b.first)
                   ans=a;
                   else if(a.first<b.first)
                   ans=b;
                   else if(a.first==b.first)
                   {
                         if(a.second<a.second)
                         ans=a;
                         else
                         ans=b;
                   }
                   return dp[ind]=ans;

  }
    long long minIncrease(vector<int>& nums) {
        vector<pair<long long,long long>>dp(nums.size(),{-1,-1});
           // int ans=0;
        // for(int i=1;i<nums.size()-1;i=i+2)
        //     {
        //          if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])continue;
        //          ans+=(max(nums[i-1],nums[i+1])+1)-nums[i];
        //              nums[i]+=(max(nums[i-1],nums[i+1])+1)-nums[i];
        //     }
            pair<long long ,long long>ans;
            ans=solve(nums,1,dp);
        return ans.second;
    }
};
// [3, 1, 4, 2, 5, 1, 6, 2, 3, 3]
    // +4   +4     +6    +5