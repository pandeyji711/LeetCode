class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans=events[0][1];
        int ind=events[0][0];
        unordered_map<int,vector<int>>m;
        m[ans].push_back(ind);
        for( int i=0;i<events.size()-1;i++)
        {
                   int x=abs(events[i][1]-events[i+1][1]);
                   if(x>=ans)
                   {
                      ind=events[i+1][0];
                      ans=x;
                      m[ans].push_back(ind);
                   }
        }
        int ans1=INT_MAX;
        for( int i=0;i<m[ans].size();i++)
        {
             ans1=min(ans1,m[ans][i]);
        }
        return ans1;
    }
};