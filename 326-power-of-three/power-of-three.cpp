class Solution {
public:
    bool isPowerOfThree(int n) {
        // double n1=n;
        //  if(n<=0)
           if(n<=0)
           return false;
        //  return false;
        // double d=log(n)/log(3);
        
        // int i=d;
        // long long  n1=1;
        while(n%3==0)
        {
              
             n=n/3;

        }
        return n==1;
    }
};