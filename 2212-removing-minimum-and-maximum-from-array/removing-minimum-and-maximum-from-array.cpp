class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int minn=INT_MAX;
       int maxx=INT_MIN;
       int minind=0;
       int maxind=0;
       int n=nums.size();
       int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
                  if(nums[i]>maxx)
                  {
                      maxind=i;
                      maxx=nums[i];
                  }
                  if(nums[i]<minn)
                  {
                     minind=i;
                     minn=nums[i];
                  }
        }
        cout<<maxind<<" "<<minind<<endl;
        //both oposit
        ans=min(ans,min(minind,maxind)+1+(n-max(minind,maxind)));
        cout<<ans<<endl;
        //both left
        ans=min(ans,min(minind,maxind)+1+(max(minind,maxind)-min(minind,maxind)));
        cout<<ans<<endl;
        //both right
        ans=min(ans,((n-max(minind,maxind))+max(minind,maxind)-min(minind,maxind)));
        cout<<n-max(minind,maxind)<<" "<<max(minind,maxind)-min(minind,maxind);
        return ans;
        
    }
};