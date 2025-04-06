class Solution {
public:
   bool solve(vector<int>& piles,int h,int mid)
   {
             for(int i=0;i<piles.size();i++)
             {
                    int x=piles[i]/mid;
                    if(piles[i]%mid!=0)
                    x++;
                    h-=x;
                    if(h<0)return false;
             }
             return h>=0;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=1e9;
        int ans=INT_MAX;;
        while(l<=r)
        {
             int mid=l+(r-l)/2;
             if(solve(piles,h,mid))
             {
                ans=mid;
                r=mid-1;

             }else
             l=mid+1;
        }
        return ans;

    }
};