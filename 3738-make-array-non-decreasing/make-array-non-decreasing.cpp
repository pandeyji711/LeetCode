class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int>v;
        v=nums;
        // sort(.begin(),nums.end());
        priority_queue<int>pq;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            {
                  m[nums[i]]++;
            }
          for(auto a1:m)
              {
                   pq.push(a1.first);
              }
        int ans=0;
         
        for(int i=nums.size()-1;i>=0;i--)
            {
                       while(!pq.empty()&&m[pq.top()]<=0)
                           {
                               pq.pop();
                           }
                      if(!pq.empty()&&pq.top()==nums[i])
                      {
                        // cout<<pq.top()<<" ";
                            m[nums[i]]--;
                          if(m[nums[i]]<=0)
                              pq.pop();
                          ans++;
                      }else{
                          m[nums[i]]--;
                         
                      }
            }
        return ans;
    }
};