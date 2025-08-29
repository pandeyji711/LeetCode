class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans=0;
        long long maxx=max(m,n);
        long long  minn=min(m,n);
        for(long long i=1;i<=maxx;i=i+2)
        {
              long long  maxstart=1+i;
              long long extra=max(1LL*0,minn-maxstart+1LL);
              ans+=min(minn,max(1LL*0,maxx-maxstart+1LL))+extra;
        }
        return ans;
    }
};