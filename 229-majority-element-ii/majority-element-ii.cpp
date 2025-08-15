class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        n=n/3;
        sort(nums.begin(),nums.end());
        int dub=nums[0];
        vector<int>ans;
        int cnt=1;
      
        for(int i=1;i<nums.size();i++)
        {
                 if(dub!=nums[i])
                 {
                       if(cnt>n)
                       ans.push_back(dub);
                       dub=nums[i];
                       cnt=0;
                       
                 }
                 cnt++;
        }
         if(cnt>n)
        ans.push_back(dub);
        return ans;
    }
};