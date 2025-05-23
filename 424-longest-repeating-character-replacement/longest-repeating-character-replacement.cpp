class Solution {
public:
  bool possible(unordered_map<char,int>&m,int &k)
  {
          int maxx=0;
          int sum=0;
          for(auto &a1:m)
          {
                maxx=max(maxx,a1.second);
                sum+=a1.second;
          }
        //    cout<<sum<<"k"<<maxx<<" ";
          if(sum-maxx<=k)return true;
          return false;
  }
    int characterReplacement(string &s, int k) {
        
      
         unordered_map<char,int>m;
        //    int cnt =mid;
        int ans=0;
           int l=0;
           int r=0;

        while(r<s.length())
        {
                m[s[r]]++;
                 
                 while(l<r&&!possible(m,k))
                 {
                     m[s[l]]--;
                   if(m[s[l]]<=0)
                   m.erase(s[l]);
                   l++;
                 }
                 if(r>=s.length())break;
                 ans=max(ans,r-l+1);
                 r++;
                 
        }
        return ans;
    }
};