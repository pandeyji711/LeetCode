class Solution {
public:
     bool ch(vector<int>& time, long long  totalTrips,long long  mid)
     {
                for(int i=0;i<time.size();i++)
                {
                            long long tr= (1LL*mid/time[i]);
                            totalTrips-=tr;
                            if(totalTrips<=0)return true;
                }
                return totalTrips<=0;
     }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1LL*0;
        long long r=LLONG_MAX/2;
        long long ans=0;
        long long tt=1LL*totalTrips;
        while(l<=r)
        {
               long long mid=l+(r-l)/2;
               if(ch(time,tt,mid))
               {
                //   cout<<mid<<" ";
                  ans=mid;
                    r=mid-1;
               }else
               l=mid+1;
        }
        return ans;
    }
};