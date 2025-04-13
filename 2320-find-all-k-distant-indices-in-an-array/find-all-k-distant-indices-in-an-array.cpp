class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    queue<pair<int,int>>q;
        for(int i=0;i<nums.size();i++)
        {
              if(nums[i]==key)
                 q.push({i-k,i+k+1});
        }
      queue<int>q2;
       vector<int>ans;
       for(int  i=0;i<nums.size();i++)
     {
                while(!q.empty()&&q.front().first<=i)
                { 
                    q2.push(q.front().second);
                    q.pop();
                }
                while(!q2.empty()&&q2.front()<=i)
                {
                      q2.pop();
                }
                if(q2.size()>0)
                ans.push_back(i);
     }
        return ans;
    }
};