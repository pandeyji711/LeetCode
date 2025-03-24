class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(),meetings.end());
            int lastav=1;
            int ans=0;
            for(int i=0;i<meetings.size();i++)
            {
                  int st=meetings[i][0];
                  int end=meetings[i][1];
                  ans+=max(0,st-lastav);
                  lastav=max(lastav,end+1);
            }
            ans+=max(0,days-lastav+1);
            return ans;
    
        }
    };