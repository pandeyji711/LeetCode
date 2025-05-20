class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // int maxx=0;
        for(int i=0;i<queries.size();i++)
        {
                pq.push({queries[i][0],queries[i][1]+1});
                // maxx=max(maxx,queries[i][1]);
        }
        priority_queue<int,vector<int>,greater<int>>pq1;
        for(int i=0;i<nums.size();i++)
        {
                while(!pq.empty()&&pq.top().first<=i)
                {
                     pq1.push(pq.top().second);
                     pq.pop();
                      
                }
                while(!pq1.empty()&&pq1.top()<=i){
                pq1.pop();
                }

                nums[i]-=pq1.size();
                // cout<< nums[i]<<" "<<pq1.size()<<endl;
                if(nums[i]>0)return 0;
        }
        return 1;
        
    }
};