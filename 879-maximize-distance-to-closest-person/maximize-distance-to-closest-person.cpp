class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
          //case 1 corner sitting
        //   l->r
        int cnt=0;
        int ans=0;
        for(int i=0;i<seats.size();i++)
        {
               if(seats[i]==1)
               break;
               cnt++;
        }
        ans=cnt;
        // r->l
        cnt=0;
        for(int i=seats.size()-1;i>=0;i--)
        {
               if(seats[i]==1)
               break;
               cnt++;
        }
        ans=max(ans,cnt);
        cnt=0;
        for(int i=0;i<seats.size();i++)
        {
                if(seats[i]==1)
                {
                     if(cnt%2!=0)
                     {
                          ans=max(ans,cnt/2+1);
                     }else{
                          ans=max(ans,cnt/2);
                     }
                     cnt=0;
                }else{
                    cnt++;
                }
        }
        return ans;
    }
};