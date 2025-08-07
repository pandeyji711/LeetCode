class Solution {
public:
  int solve(vector<int>& nums,int mid)
  {
      int ans=0;
       int diff=INT_MAX;
            for(int i=0;i<nums.size();i++)
            {
                   int req=mid-nums[i];
                   int l=i+1;
                   int r=nums.size()-1;
                   while(l<r)
                   {
                         if(nums[l]+nums[r]==req)
                         {
                            // cout<<"k";
                            return mid;
                            }
                          if(diff>abs(mid-(nums[l]+nums[r]+nums[i])))
                                {
                                    // cout<<i<<" "<<l<<" "<<r<<endl;
                                //    cout<< nums[l]<<" "<<nums[r]<<" "<<nums[i]<<endl;
                                      ans=nums[l]+nums[r]+nums[i];
                                    //   cout<<ans<<" ";
                                      diff=abs(mid-(nums[l]+nums[r]+nums[i]));
                                }
                         

                         else if(nums[l]+nums[r]<req)
                         {  
                               
                              l++;
                         }else{
                            r--;
                         }

                   }
            }
            // cout<<ans<<" ";
            return ans;

  }
    int threeSumClosest(vector<int>& nums, int target) {
        // int l=0;
        // int r=4000;
        // int ans=0;
        sort(nums.begin(),nums.end());
        // // cout<<solve(nums,2);
        // while(l<=r)
        // {
        //       int mid=l+(r-l)/2;
        //       int n1=target+mid;
        //       int n2=target-mid;
        //       if(solve(nums,n1)||solve(nums,n2))
        //       {
        //         cout<<"k";
        //            ans=n2;
        //            r=mid-1;
        //       }else
        //        l=mid+1;

        // }
        return solve(nums,target);
    }
};