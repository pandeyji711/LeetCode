class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++)
        {
             m[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto a1:m)
        {
              if(a1.second.size()<3)continue;
                for(int i=1;i<a1.second.size()-1;i++)
                {
                       ans=min(ans,abs(a1.second[i-1]-a1.second[i])+abs(a1.second[i]-a1.second[i+1])+abs(a1.second[i+1]-a1.second[i-1]));
                }
        }
        return ans==INT_MAX?-1:ans;
    }
};