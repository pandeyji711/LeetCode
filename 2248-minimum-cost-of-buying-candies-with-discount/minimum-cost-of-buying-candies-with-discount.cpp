class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int ans=0;
        int cnt=0;
        for(int i=0;i<cost.size();i++)
        {
              if(cnt==2)
              {
                cnt=0;
                continue;
              }
              ans+=cost[i];
              cnt++;
        }
        return ans;
    }
};