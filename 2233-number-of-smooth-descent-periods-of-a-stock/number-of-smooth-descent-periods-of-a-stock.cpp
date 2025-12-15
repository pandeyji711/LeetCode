class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int ind=0;
        long long ans=0;
        while(ind<prices.size())
        {
              long long  cnt=0;
              while(ind<prices.size()-1&&prices[ind]==prices[ind+1]+1)
              {
                cnt++;
                ind++;
              }
              if(cnt==0)
              {
                 ind++;
                 continue;
              }
            //   cout<<ind<<" "<<cnt<<endl;
              ans=ans+(cnt+1)*1LL*(cnt+2)/2-(cnt+1);
        }
    return ans+prices.size();    
    }
};