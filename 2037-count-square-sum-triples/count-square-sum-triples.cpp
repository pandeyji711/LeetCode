class Solution {
public:

    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<n;i++)
        {
              for(int j=i+1;j<n;j++)
              {
                     double sum=i*i+j*j;
                     int sum1=sqrt(sum);
                     double sum2=(double)sqrt(sum);
                     if(sum1==sum2&&sum1<=n)
                     {
                        
                          ans+=2;
                     }
              }
        }
        return ans;
    }
};