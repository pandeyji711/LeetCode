class Solution {
public:

    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>>pq;
        //time,step,x,y
        vector<vector<int>>cost(moveTime.size(),vector<int>(moveTime[0].size(),INT_MAX));
        pq.push({{0,0},{0,0}});
        cost[0][0]=0;
        while(!pq.empty())
        {
              auto &it=pq.top();
               int x=it.second.first;
               int y=it.second.second;
               int w=it.first.first;
               int step=it.first.second;
               pq.pop();
              // up
               if(x-1>=0)
               {
                      
                      int time=max(moveTime[x-1][y],w);
                       int extra=((step+1)%2==0?2:1);
                       int curr=time+extra;
                     int stored=cost[x-1][y];
                      if(curr<stored)
                      {
                              cost[x-1][y]=curr;
                              pq.push({{curr,step+1},{x-1,y}});
                      }
                     
               }
               //down
                if(x+1<=moveTime.size()-1)
               {
                      
                      int time=max(moveTime[x+1][y],w);
                       int extra=((step+1)%2==0?2:1);
                       int curr=time+extra;
                     int stored=cost[x+1][y];
                    //  cout<<curr<<" "<<stored<<endl;
                      if(curr<stored)
                      {
                            //    cout<<curr<<" "<<stored<<endl;
                              cost[x+1][y]=curr;
                              pq.push({{curr,step+1},{x+1,y}});
                      }
                     
               }
               //left
                if(y-1>=0)
               {
                      
                      int time=max(moveTime[x][y-1],w);
                       int extra=((step+1)%2==0?2:1);
                       int curr=time+extra;
                     int stored=cost[x][y-1];
                      if(curr<stored)
                      {
                              cost[x][y-1]=curr;
                              pq.push({{curr,step+1},{x,y-1}});
                      }
                     
               }
               //right
                if(y+1<=moveTime[0].size()-1)
               {
                      
                      int time=max(moveTime[x][y+1],w);
                       int extra=((step+1)%2==0?2:1);
                       int curr=time+extra;
                     int stored=cost[x][y+1];
                      if(curr<stored)
                      {
                              cost[x][y+1]=curr;
                              pq.push({{curr,step+1},{x,y+1}});
                      }
                     
               }
        }
        return cost[moveTime.size()-1][moveTime[0].size()-1];
    }
};