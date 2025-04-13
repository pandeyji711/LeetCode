class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        map<vector<int>,int>m;
        for(int i=0;i<nums.size();i++)
        {
                  long long  x=target-nums[i];
                  for(int j=i+1;j<nums.size();j++)
                  {
                          long long  y=(x-nums[j]);
                         long long l=j+1;
                         long long r=nums.size()-1;
                         while(l<r)
                         {
                               if(nums[l]+nums[r]==y)
                               {
                                    if(m.find({nums[i],nums[j],nums[l],nums[r]})==m.end()){
                                   ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                                    m[{nums[i],nums[j],nums[l],nums[r]}]=1;
                                    }
                                // cout<<"k";
                                l++;
                                r--;
                               }else if(nums[l]+nums[r]>y)
                               {
                                      r--;
                               }else
                               l++;
                         }
                  }
        }
        return ans;
    }
};