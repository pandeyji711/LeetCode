class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int n1=n;
        while(n)
        {
              sum+=n%10;
              pro=pro*(n%10);
              n=n/10;

        }

        return (n1%(sum+pro)==0);

    }
};