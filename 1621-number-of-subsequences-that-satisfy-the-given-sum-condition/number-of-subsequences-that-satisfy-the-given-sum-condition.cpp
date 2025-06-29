class Solution {
public:
  int mod =1e9+7;
   long long powmod(int b )
   {
     long long  result =1;
     long long  a=2;
               a %= mod; // Reduce a if it's >= m

    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
   }
    int numSubseq(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        int cnt=0;
        int ans=0;
        while(l<=r)
        {
                 if(nums[l]+nums[r]<=k)
                 {
                       int tem=r-l;
                       int count=((int)powmod(tem)%mod)-1;
                   ans=(ans%mod+count%mod)%mod;
                    if(nums[l]*2<=k)
                   cnt++;
                   l++;
                  
                 }else {
                       if(nums[r]*2<=k)
                   cnt++; 

                   r--;   
                 }
        }
        return (ans%mod+cnt)%mod;
    }
};