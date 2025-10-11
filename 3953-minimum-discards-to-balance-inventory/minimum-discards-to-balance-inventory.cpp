class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int,int>mp;
        
        int l=0;
        int r=0;
        int ans=0;
        vector<bool>keep(arrivals.size(),true);
        while(r<arrivals.size())
        {
               mp[arrivals[r]]++;
               if(r-l+1>w)
               {
                  if(keep[l])
                  mp[arrivals[l]]--;
                  l++;
               }
               if(mp[arrivals[r]]>m)
               {
                  keep[r]=false;
                    mp[arrivals[r]]--;
                    // mp[rand]++;
                    // rand++;
                    ans++;
                    
                    
               }
               r++;
        }
        return ans;
    }
};
// [3,3,3,3,3,3,3]