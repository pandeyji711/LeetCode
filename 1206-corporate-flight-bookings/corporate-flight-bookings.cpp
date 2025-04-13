class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        for(int i=0;i<bookings.size();i++)
        {

                 q.push(bookings[i]);
        }
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q2;
       vector<int>ans;
       int sum=0;
       for(int  i=1;i<=n;i++)
     {
                while(!q.empty()&&q.top()[0]<=i)
                { 
                    q2.push({q.top()[1]+1,q.top()[2]});
                    sum+=q.top()[2];
                    q.pop();
                }
                while(!q2.empty()&&q2.top().first<=i)
                {
                    sum-=q2.top().second;
                      q2.pop();
                }
               
                ans.push_back(sum);
     }
        return ans;
    }
};