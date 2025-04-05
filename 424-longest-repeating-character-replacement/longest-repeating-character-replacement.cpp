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
  bool solve(string &s, int &k,int mid)
  {
           unordered_map<char,int>m;
           int cnt =mid;
           int l=0;
           int r=0;
           while(cnt--)
           {
                 m[s[r]]++;
                 r++;
           }

           if(possible(m,k))
           return true;
        //    r++;
           while(r<s.length())
           {
                   m[s[r]]++;
                   m[s[l]]--;
                   if(m[s[l]]<=0)
                   m.erase(s[l]);
                    if(possible(m,k))
                      return true;
                      r++;
                      l++;

           }
           return false;
  }
    int characterReplacement(string s, int k) {
        
        int l=0;
        int r=s.length();
        int ans=0;
        while(l<=r)
        {
              int mid=l+(r-l)/2;
              if(solve(s,k,mid))
              {
                //   cout<<mid<<endl;
                      ans=mid;
                      l=mid+1;
              }else
              r=mid-1;
        }
        return ans;
    }
};