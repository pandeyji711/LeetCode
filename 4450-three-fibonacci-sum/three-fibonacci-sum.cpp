class Solution {
public:
    bool threeFibonacciSum(int n) {
        int sum=2;
        if(n<sum)return false;
        if(n==sum)return true;
        int a=1;
        int b=1;
        while(sum<n)
        {
             sum=2*(a+b);
            
             if(sum==n)return true;
             int c=a+b;
             a=b;
             b=c;
             
          
            //  cout<<sum<<" "<<a<<" "<<b<<endl;
        }
        return false;
    }
};