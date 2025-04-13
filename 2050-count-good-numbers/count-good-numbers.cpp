class Solution {
public:
  long long const mod=1e9+7;

   long long po(long long base, long long  ex)
   {
            long long res=1;
            while(ex>0)
            {
                    if(ex%2==1)
                    {
                           res=(res*base)%mod;
                    }
                    base=(base*base)%mod;
                    ex=ex/2;
            }
            return res;
   }
    int countGoodNumbers(long long n) {
          long long  odd_digits=n/2;
        long long even_digits=(n+1)/2;
          long long even=(po(5,even_digits));
          long long odd=(po(4,odd_digits));
        //   for(int i=0;i<odd_digits;i++)
        //   {
        //            odd=((odd%mod)*4)%mod;
        //   }
        //    for(int i=0;i<even_digits;i++)
        //   {
        //            even=((even%mod)*5)%mod;
        //   }
          long long ans=(((odd)%mod)*((even)%mod));
          return ans%mod;
    }
};