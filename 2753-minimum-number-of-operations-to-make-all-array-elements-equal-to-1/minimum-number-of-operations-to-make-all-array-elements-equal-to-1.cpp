class Solution {
public:
    int solve(vector<int> nums,int i)
    {
        
            int cnt=0;
            while(i>=0)
            {
                     if(gcd(nums[i],nums[i+1])<nums[i])
                     {
                        
                         if(gcd(nums[i],nums[i+1])==1)return cnt+1;
                           nums[i]=gcd(nums[i],nums[i+1]);
                        //    cout<<nums[i]<<" "<<i<<endl;
                          
                           cnt++;
                     }
                        i--;
                     
                     
            }
            return -1;
    }
    int minOperations(vector<int>& nums) {
        int ans=INT_MAX; 
        int n=nums.size();
         int ones = count(nums.begin(), nums.end(), 1);

        if (ones > 0) 
            return n - ones;
        for(int i=0;i<nums.size()-1;i++)
        {
             int tem=solve(nums,i);
                 if(tem!=-1)
                 {
                     ans=min(ans,tem);
                 }
        }
        // cout<<ans;
        return ans==INT_MAX?-1:ans+nums.size()-1;
    
    }
};