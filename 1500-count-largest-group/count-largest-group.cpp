class Solution {
public:
  int sum(int n)
  {
     int sum=0;
         while(n)
         {
                     sum+=n%10;
                     n=n/10;
         }
         return sum;
  }
    int countLargestGroup(int n) {
        vector<int>m(37,0);
        int maxx=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int s=sum(i);
               m[sum(i)]++;
               if(m[s]>maxx)
               {
                maxx=m[s];
                cnt=1;
               }else if(m[s]==maxx)
               cnt++;
        }
        return cnt;
    }
};