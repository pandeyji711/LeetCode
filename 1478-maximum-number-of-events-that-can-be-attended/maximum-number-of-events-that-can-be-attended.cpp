class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int minn=INT_MAX;
        int maxx=0;
        
        for(int i=0;i<events.size();i++)
        {
               pq.push({events[i][0],events[i][1]});
               minn=min(minn,events[i][0]);
               maxx=max(maxx,events[i][1]);
        }
        int ans=0;
          priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq1;
        priority_queue<int>q;
        vector<int>v(maxx,0);
        // cout<<pq.size();
        // cout<<maxx<<" ";
        for(int i=minn;i<=maxx;i++)
        {
               while(!pq.empty()&&pq.top().first==i)
               {
                    int diff=pq.top().second-pq.top().first;
                    pq1.push({pq.top().second,pq.top().first});
                    pq.pop();
               }
                while(!pq1.empty()&&pq1.top()[0]<i)
                   pq1.pop();
                   if(!pq1.empty()&&(pq1.top()[1]<=i&&i<=pq1.top()[0]))
                   {
                    //   cout<<pq.top().first<<" "<<pq.top().second<<endl;
                         ans++;
                        //  cout<<i<<" ";
                         pq1.pop();
                   }
                //    if(pq.empty())cout<<i;

               
        }
        return ans;
    }
};