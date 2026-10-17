class Solution {
public:
 bool prime (int a)
 {
        if(a<=1)return false;
        if(a==2)return true;
        if(a%2==0)return false;
        for(int i=3;i*i<=a;i+=2)
        {
             if(a%i==0)return false;
        }
        return true;
 }
    vector<int> maxPrimes(int n, int s) {
        vector<int>ans;
        int sum=0;
         for(int i=2;i<=n;i++)
         {
               if(prime(i))
               {  
                // cout<<i<<" ";
                  sum+=i;
                  if(sum>s)return ans;
                  ans.push_back(i);
                  
               }
         }
         return ans;
         
    }
};