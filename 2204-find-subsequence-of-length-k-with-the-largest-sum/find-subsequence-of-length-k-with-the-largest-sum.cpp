class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
      
        vector<pair<int,int>>vp;
        for(int i=0;i<nums.size();i++)
        {
                vp.push_back({nums[i],i});
        }
          sort(vp.rbegin(),vp.rend());
          sort(vp.begin(),vp.begin()+k,[](pair<int,int>&a,pair<int,int>&b){
                          return a.second<b.second;
          });
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
                 ans.push_back(vp[i].first);
        }
        return ans;
    }
};