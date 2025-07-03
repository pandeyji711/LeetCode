class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        //first window

        for(int i=0;i<k;i++)
        {
              pq.push({nums[i],i});
        }
        vector<int>ans;
        ans.push_back(pq.top().first);
        int l=0;
        int r=k;
        while(r<nums.size())
        {
              pq.push({nums[r],r});
              l++;
              while(!pq.empty()&&pq.top().second<l)
              pq.pop();
              ans.push_back(pq.top().first);
              r++;
        }
        return ans;
    }
};