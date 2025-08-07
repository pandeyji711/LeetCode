class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int ans=0;
        int diff=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
             for(int j=i+1;j<nums.size();j++)
             {
                  for(int k=j+1;k<nums.size();k++)
                  {
                            int tem=nums[i]+nums[j]+nums[k];
                            int di=abs(target-tem);
                            if(di==0)
                            {
                                // cout<<tem<<" "<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                                return target;
                            }else if(di<diff)
                            {
                                  ans=tem;
                                //   cout<<tem<<" ";
                                  diff=di;
                            }
                  }
             }
        }
        return ans;
    }
};