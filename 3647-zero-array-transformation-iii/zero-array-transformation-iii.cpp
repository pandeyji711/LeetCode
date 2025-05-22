class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
          for(int i=0;i<queries.size();i++)
          {
               int diff=queries[i][0]-queries[i][1];
               pq.push({queries[i][0],queries[i][1]+1});
          }

          int ans=0;
        //   int curr=-1;
           priority_queue<int,vector<int>,greater<int>>curr;
            priority_queue<int>box;

           for(int i=0;i<nums.size();i++)
           {
                 while(!pq.empty()&&pq.top().first<=i)
                 {
                         box.push(pq.top().second);
                         pq.pop();
                 }
             
                 while(!curr.empty()&&curr.top()<=i){      
                 curr.pop();
                 }
                 int diff=nums[i]-curr.size();
                 
                 while(!box.empty()&&diff>0&&box.top()>i)
                 {
                    ans++;
                            curr.push(box.top());
                            box.pop();
                            diff--;
                 }
                 if(diff>0)return -1;
             



           }
           return queries.size()-ans;
          
    }
};