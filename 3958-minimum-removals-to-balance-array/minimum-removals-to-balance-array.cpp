class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        queue<pair<int ,long long >>q;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
                      while(!q.empty()&&q.front().second<nums[i])
                      {
                                int tem=q.front().first+nums.size()-i;
                                ans=min(ans,tem);
                                q.pop();
                      }
                      q.push({i,1LL*k*nums[i]});
        }
    
        
                int tem=q.front().first;
                                ans=min(ans,tem);
                  
        return ans==INT_MAX?0:ans;
    }
};