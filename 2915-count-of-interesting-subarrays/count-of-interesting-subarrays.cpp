class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // long lon
        int n=nums.size();
        vector<int>pre(n+1,0);
        pre[0]=0;
        int sum=0;
           unordered_map<int,long long >m;
        long long  ans=0;
        m[0]++;
        // pre[0]=(nums[0]%modulo==k)?1:0;
        for(int i=0;i<n;i++)
        {
                int now=(nums[i]%modulo==k)?1:0;
                sum+=now;;     //prefixsum
               int r= sum%modulo;
               int r2=(r-k+modulo)%modulo; //formula
             if(m.find(r2)!=m.end())   
               ans+=m[r2];
               
               m[r]++;
         }
       
        
         return ans;
    }
};
// mm=3,k=0;
// [1,0,1,1,1]
// [0,0,0,1,1,1,2,2,2,3,3,3,4,4,4...]
// [1,1,1]


