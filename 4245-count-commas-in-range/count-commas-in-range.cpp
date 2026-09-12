class Solution {
public:
    int countCommas(int n) {
         int ans=0;
         for(int i=1;i<=n;i++)
         {
                int cnt=0;
                int n1=i;
                while(n1>0)
                {
                     n1=n1/10;
                     cnt++;

                }
                if(cnt>3)
                {
                     if(cnt%3==0)
                 ans=ans+cnt/3-1;
                 else
                 ans=ans+cnt/3;
                   
                }

         }
         return ans;
    }
};

