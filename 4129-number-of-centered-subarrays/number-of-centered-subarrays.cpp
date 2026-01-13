class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
       int ans=0;
        for(int i=0;i<nums.size();i++)
        {
             unordered_map<int,int>m;
             int sum=0;
              for(int j=i;j<nums.size();j++)
              {
                      sum+=nums[j];
                      m[nums[j]]=1;
                      if(m.count(sum))ans++;
              }
        }
        return ans;
    }
};