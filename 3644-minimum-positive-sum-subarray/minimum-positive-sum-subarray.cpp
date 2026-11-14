class Solution {
public:
 int  solve(vector<int>& nums,int siz)
 { 
          int minn=INT_MAX;
          int siz1=siz;
          int sum=0;
          int r=0;
          while(siz1>0)
          {
              sum+=nums[r];
              r++;
              siz1--;
          }
          if(sum>0)
          minn=min(minn,sum);
          int l=0;
        //   cout<<minn<<endl;
          while(r<nums.size())
          { 
               sum+=nums[r];
               sum-=nums[l];
               l++;
               r++;
               if(sum>0)
               minn=min(sum,minn);
          }
          return minn;
 }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minn=INT_MAX;
           for(int i=l;i<=r;i++)
           {
                int x=solve(nums,i);
                // cout<<x<<"g";
                if(x>0)
                {
                     minn=min(minn,x);
                }
           }
           return minn==INT_MAX?-1:minn;

    }
};