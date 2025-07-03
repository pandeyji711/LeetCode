class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq; // first element is num form priority and second for index
        // first window
        for(int i=0;i<k;i++)    
        {   pq.push({nums[i],i});
         }
        vector<int>ans;
        ans.push_back(pq.top().first); //pq.top() gives max element
        int l=0,r=k;
        while(r<nums.size())
        { pq.push({nums[r],r});  //push the element of new window
             l++; // srink the window
              while(!pq.empty()&&pq.top().second<l) 
              pq.pop();   // remove expire element not belong to thst window
              ans.push_back(pq.top().first); //add the max element form that window
              r++;   // expand the windo
              }
        return ans; 
        }
};