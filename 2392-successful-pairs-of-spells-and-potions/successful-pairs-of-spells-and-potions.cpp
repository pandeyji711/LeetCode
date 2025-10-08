class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans(spells.size(),0);
        for(int i=0;i<spells.size();i++)
        {
                  long long  div=success/spells[i];
                  if(success%spells[i]!=0)
                  div++;
                  auto it =lower_bound(potions.begin(),potions.end(),div);
                  if(it==potions.end())
                  ans[i]=0;
                  else{
                         int index=it-potions.begin();
                         int cnt=potions.size()-index;
                         ans[i]=cnt;
                  }
        }
        return ans;
    }
};