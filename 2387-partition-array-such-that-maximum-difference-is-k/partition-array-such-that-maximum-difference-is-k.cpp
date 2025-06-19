class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int minn=nums[0];
        int maxx=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            //   cout<<maxx<<" "<<minn<<" "<<i<<endl;
             
               maxx=max(maxx,nums[i]);
               minn=min(minn,nums[i]);
                 if(maxx-minn>k)
               {
                //    cout<<i<<" ";
                      ans++;
                      maxx=nums[i];
                      minn=nums[i];
                        
               }
        }
         if(maxx-minn>k)
               {
                  
                      ans++;
                     
               }

        return ans+1;
    }
};