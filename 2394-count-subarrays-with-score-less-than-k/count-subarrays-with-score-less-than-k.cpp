class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // long long ans=0;
        int l=0;
        int r=0;
        long long sum=0;
        long long ans=0;
        long long  cnt=0;
        long long  n=nums.size();
        long long score=0;
        while(r<nums.size())
        {
            sum+=nums[r];
             cnt++;
            score=sum*cnt;
             while(score>=k)
             {
                // cout<<l<<" "<<r<<endl;
                  ans+=n-r;
                    sum-=nums[l];
                    cnt--;
                    score=sum*cnt;
                    l++;
             }
             r++;
        }
        long long total =n*(n+1)/2;
        // cout<<ans<<" "<<total;
        return total-ans;
    }
};