class Solution {
    public:
        int minimumCardPickup(vector<int>& cards) {
            unordered_map<int,int>m;
            int l=0;
            int r=0;
            int ans=INT_MAX;
            while(r<cards.size())
            {
                   m[cards[r]]++;
                   while(l<=r&&m[cards[r]]>=2)
                   {
                        m[cards[l]]--;
                        ans=min(ans,r-l+1);
                        l++;
                   }
                   r++;
            }
            return ans==INT_MAX?-1:ans;
        }
    };