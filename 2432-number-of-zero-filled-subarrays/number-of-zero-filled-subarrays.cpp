class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      long long ans=0;
      int dub=0;
      long long cnt=0;
        for(int i=0;i<nums.size();i++)
        {
                if(dub!=nums[i])
                {
                      long long tem=cnt*(cnt+1)/2;
                    //   cout<<cnt<<" ";
                      ans+=tem;
                      cnt=0;
                }
                if(nums[i]==0)
                cnt++;
        }
        long long tem=cnt*(cnt+1)/2;
                      ans+=tem;
                      cnt=0;
 return ans;
                      
    }
};