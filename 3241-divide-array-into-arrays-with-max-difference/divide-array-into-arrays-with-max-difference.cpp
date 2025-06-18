class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int slice=0;
        int minn=nums[0];
        int maxx=nums[0];
        vector<int>tem;
        tem.push_back(nums[0]);
        vector<vector<int>>ans;
        for(int i=1;i<nums.size();i++)
        {
              if(maxx-minn>k)
              {
                   return vector<vector<int>>();
              }
              if(tem.size()==3)
              {
                    ans.push_back(tem);
                    tem.clear();
                    minn=INT_MAX;
                    maxx=0;
                    // cout<<i<<" ";

              }
              
              tem.push_back(nums[i]);
              maxx=max(nums[i],maxx);
              minn=min(nums[i],minn);
        }
         if(maxx-minn>k)
              {
                   return vector<vector<int>>();
              }
        ans.push_back(tem);
        // cout<<ans.size()<<" ";
        return ans;
    }
};