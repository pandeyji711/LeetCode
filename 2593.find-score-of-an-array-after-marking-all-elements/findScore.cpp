class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         int n=nums.size();
        for( int i=0;i<n;i++)
        {
                pq.push({nums[i],i});
        }
       
        vector<int>vis(n,0);
        long long ans=0;
        int mark=n;
        while(!pq.empty())
        {
               while(!pq.empty()&&vis[pq.top().second]==1)
               {
                    pq.pop();
               }
               if(!pq.empty()){
               int x=pq.top().first;
               ans+=x;
              
               int ind=pq.top().second;
               vis[ind]=1;
            //    mark
               //left vis
               if(ind>0)
               vis[ind-1]=1;
               //right vis
               if(ind+1<n)
               vis[ind+1]=1;
                pq.pop();
               }

        }
        return ans;
    }
};