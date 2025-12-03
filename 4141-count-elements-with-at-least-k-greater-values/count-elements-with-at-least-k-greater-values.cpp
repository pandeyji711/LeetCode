class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        vector<int>v;
        
        sort(nums.begin(),nums.end());
        int dub=nums[0];
        int n=nums.size();
        int ans=0;
   int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
                  if(dub!=nums[i])
                  {
                    // cout<<dub<<" ";
                    if(n-i>=k)
                    ans+=cnt;
                   
                     dub=nums[i];
                     cnt=1;
                    //  vp.push_back()
                  }else{
                    cnt++;
                  }

        }
        
                    // cout<<dub<<" ";
                    if(1>k)
                    ans+=cnt;
                   
                   
        // v.push_back(dub);
        // cout<<v.size();
        // int n=v.size();
        return ans;
    }
};