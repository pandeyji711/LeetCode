class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int siz=0;
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.length())
        {
               m[s[r]]++;
               if(m[s[r]]==2)
               siz++;
               while(siz>0&&l<r)
               {
                      m[s[l]]--;
                      if(m[s[l]]==1)
                      siz--;
                      l++;
               }
               ans=max(ans,r-l+1);
               r++;
        }
        return ans;
    }
};