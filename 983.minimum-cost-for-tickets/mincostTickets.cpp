class Solution {
public:
   int solve(vector<int>& days, vector<int>& costs, int tdays,int ind, vector<vector<int>>&dp)
   {
                 if(ind>=days.size())
                 return 0;
                 if(dp[tdays][ind]!=-1)
                 return dp[tdays][ind];
                 int x=0;
                 int y=0;
                 int z=0;
                 //cost[0];
                 if(days[ind]<tdays)
                 {
                    x=solve(days,costs,tdays,ind+1,dp);
                 }else{
                    tdays=max(tdays,days[ind]);
                    x=costs[0]+solve(days,costs,tdays+1,ind+1,dp);
                 }
                 //cost[1];
                  if(days[ind]<tdays)
                 {
                    y=solve(days,costs,tdays,ind+1,dp);
                 }else{
                    tdays=max(tdays,days[ind]);
                    y=costs[1]+solve(days,costs,tdays+7,ind+1,dp);
                 }
                 //cost[2];
                  if(days[ind]<tdays)
                 {
                    z=solve(days,costs,tdays,ind+1,dp);
                 }else{
                    tdays=max(tdays,days[ind]);
                    z=costs[2]+solve(days,costs,tdays+30,ind+1,dp);
                 }
                 return  dp[tdays][ind]=min({x,y,z});
   }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<vector<int>>dp(450,vector<int>(450,-1));
         return solve(days,costs,0,0,dp);
    }
};