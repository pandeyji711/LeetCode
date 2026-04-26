class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>m;
        int gr=0;
        for(int i=0;i<nums.size();i++)
        {
             if(gr<nums[i])
             {
                  ans.push_back(nums[i]);
                  m[i]=1;
                  gr=nums[i];
             }
        }
        gr=0;
        int ind=ans.size();
          for(int i=nums.size()-1;i>=0;i--)
        {
             if(gr<nums[i]&&!m.count(i))
             {
                  ans.push_back(nums[i]);
                  m[i]=1;
                  
                //   gr=nums[i];
                //   cout<<gr<<endl;
             }
             gr=max(gr,nums[i]);
        }
        reverse(ans.begin()+ind,ans.end());
        return ans;

    }
};