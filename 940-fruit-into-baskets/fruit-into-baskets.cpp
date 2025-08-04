class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int type=0;
        unordered_map<int,int>m;
        int l=0;
        int r=0;
        int ans=0;
        while(r<fruits.size())
        {
               m[fruits[r]]++;
               if(m[fruits[r]]==1)
               type++;
               while(type>2)
               {
                    // ans=max(ans,r-l+1);
                    m[fruits[l]]--;
                    if(m[fruits[l]]==0)
                    type--;
                    l++;
               }
               ans=max(ans,r-l+1); 
               r++;
        }
        return ans;

    }
};