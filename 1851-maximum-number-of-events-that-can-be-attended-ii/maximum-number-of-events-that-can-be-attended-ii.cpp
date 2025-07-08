class Solution {
public:
  int solve(vector<vector<int>>& events,int ind,int k,int &maxx, vector<vector<int>>&dp )
  {
                if(ind>=events.size())
                return 0;
                if(k==0)
                return 0;
                int a=0;
                int b=0;
                if(dp[ind][k]!=-1)return dp[ind][k];
                //pick
                //search for next index to pick
                int last=events[ind][1];
                if(last+1>maxx)return dp[ind][k]=max(events[ind][2],solve(events,ind+1,k,maxx,dp));
                int i=ind+1;
                while(i<events.size()&&events[i][0]<last+1)
                {
                     i++;
                }
                // cout<<i<<" ";
                a=events[ind][2]+solve(events,i,k-1,maxx,dp);
                b=solve(events,ind+1,k,maxx,dp);
                return dp[ind][k]=max(a,b);


             

  }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int maxx=0;
        vector<vector<int>>dp(events.size()+1,vector<int>(k+1,-1));
        for(int i=0;i<events.size();i++)
        {
            //  cout<<events[i][0]<<" "<<events[i][1]<<endl;
               maxx=max(maxx,events[i][0]);
        }
        return solve(events,0,k,maxx,dp);


    }
};