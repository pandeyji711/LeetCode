class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        vector<int>neg(nums.size()+1,INT_MAX);
        vector<int>pos(nums.size()+1,INT_MIN);
         for(int i=0;i<nums.size();i++)
         {
                    neg[i+1]=min(neg[i],nums[i]);
                    
                    pos[i+1]=max(pos[i],nums[i]);
                    // cout<<neg[i]<<" "<<pos[i]<<endl;
         }
         long long ans=LLONG_MIN;
         for(int i=nums.size()-1;i>=0;i--)
         {
                 int ind=i-m+1;
                 if(ind>=0)
                 {
                      long long tem;
                      if(nums[i]>=0)
                      tem=1LL*(pos[ind+1])*nums[i];
                      else{
                        // cout<<neg[ind]<<" "<<ind<<endl;
                       tem=1LL*(neg[ind+1])*nums[i];
                      }

                       ans=max(ans,tem);
                    
                 }
         }
         return ans;
    }
};