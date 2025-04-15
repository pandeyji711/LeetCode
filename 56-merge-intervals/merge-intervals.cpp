class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       
        queue<pair<int,int>>pq;
        vector<int>v;
       sort(intervals.begin(),intervals.end());
 for(int i=0;i<intervals.size();i++)
        {
                pq.push({intervals[i][0],intervals[i][1]});
                v.push_back(intervals[i][0]);
                v.push_back(intervals[i][1]);

        }
        priority_queue<int,vector<int>,greater<int>>pq1;
       int  st=-1;
       sort(v.begin(),v.end());
       vector<vector<int>>ans;
       for(int i=0;i<v.size();i++)
       {
                  while(!pq.empty()&&pq.front().first<=v[i])
                  {
                          pq1.push(pq.front().second);
                    
                          if(st==-1)
                             st=v[i];

                          pq.pop();

                  }
                  while(!pq1.empty()&&pq1.top()<=v[i])
                  {
                       pq1.pop();
                  }
                  if(pq1.empty()&&st!=-1)
                  {
                      
                       ans.push_back({st,v[i]});
                       st=-1;
                  }
       }
       return ans;
    }
};