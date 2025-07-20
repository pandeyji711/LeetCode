class Solution {
public:
bool isprime(int n)
{
       if(n<=1)return false;
       if(n==2)return true;
       if(n%2==0)return false;
       for(int i=3;i*i<=n;i=i+2)
       {
           if(n%i==0)return false;
       }
       return true;
}
    long long splitArray(vector<int>& nums) {
        long long suma=0;
        long long sumb=0;
        for(int i=0;i<nums.size();i++)
        {
             if(isprime(i)){
                // cout<<i<<" ";
             suma+=nums[i];
             
             }
             else
             sumb+=nums[i];
        }
     
        return abs(suma-sumb);
    }
};