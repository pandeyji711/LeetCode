class Solution {
public:
   bool check(vector<int>& nums, int p,int mid)
   {
             for(int i=0;i<nums.size()-1;i++)
             {
                    if(abs(nums[i]-nums[i+1])<=mid)
                    {
                         p--;
                         i++;
                    }
                    if(p<=0)
                    return true;
             }
             return p<=0;
   }
    int minimizeMax(vector<int>& nums, int p) {
         sort(nums.begin(),nums.end());

         int l=0;
         int r=abs(nums[0]-nums[nums.size()-1]);
         int ans=0;
         while(l<=r)
         {
            int mid=l+(r-l)/2;
              if(check(nums,p,mid))
              {
                  ans=mid;
                  r=mid-1;
              }
              else{
                   l=mid+1;
              }
         }
         return ans;
            
    }
};