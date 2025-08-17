class Solution {
public:
 static bool  com(const vector<int>&a,const vector<int>&b)
                                {
                                        return a[0]<b[0];
                                                       
                                }
  int solve(vector<vector<int>>&data,int st,vector<int>&dp)
  {
                           if(st>=data.size())
                              return 0;
                               if(dp[st]!=-1)
                              {
                                  return dp[st];
                              }
                              int x=0;
                              int y=0;
                             
                             

                                      vector<int>tem={data[st][1],0,0};
                              auto ind=lower_bound(data.begin(),data.end(),tem,com);
                              if(ind==data.end())
                               return dp[st]= max(data[st][2],solve(data,st+1,dp));
                               else{
                               int index=ind-data.begin();
            
                                x=data[st][2]+solve(data,index,dp);
                    
                              y=solve(data,st+1,dp);
                               }
                                return  dp[st]=max(x,y);
                            

  }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>data;
        vector<int>dp(startTime.size()+1,-1);
        for(int i=0;i<startTime.size();i++)
        {
               data.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(data.begin(),data.end(),com);
        return solve(data,0,dp);
    }
};