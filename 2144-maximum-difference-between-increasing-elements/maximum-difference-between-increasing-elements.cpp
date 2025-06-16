class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        vector<int>maxx(nums.size()+1,INT_MIN);
        vector<int>minn(nums.size()+1,INT_MAX);
        for(int i=0;i<nums.size();i++)
        {
               minn[i+1]=min(minn[i],nums[i]);
               cout<<minn[i+1]<<" ";
               
        }
        cout<<endl;
          for(int i=nums.size()-1;i>=0;i--)
        {
               maxx[i+1]=max(maxx[i],nums[i]);
               cout<<maxx[i+1]<<" ";
               
        }
        cout<<endl;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
                int tem=maxx[i+1]-minn[i];
                ans=max(ans,tem);
        }
        return ans==0?-1:ans;


    }
};