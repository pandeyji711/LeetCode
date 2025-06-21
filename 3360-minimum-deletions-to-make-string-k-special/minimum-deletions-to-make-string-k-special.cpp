class Solution {
public:
 int solve(  vector<int>&v,int k,int val)
 {
     int ansl=0;
     //-k
     
        int l=max(0,val-k);
        
          for(int i=0;i<v.size();i++)
          {
                  if(v[i]>=val)
                  {
                    ansl+=(v[i]-val);
                  }else if(v[i]>=l)
                  {
                      continue;
                  }else{
                    ansl+=v[i];
                  }
          }
          int ansr=0;
          int r=val+k;
          for(int i=0;i<v.size();i++)
          {
                     if(v[i]>=r)
                     {
                        ansr+=v[i]-r;
                     }else if(v[i]>=val){
                                 continue;

                     }else{
                        ansr+=v[i];
                     }
          }
          return min(ansr,ansl);

       
 }
    int minimumDeletions(string s, int k) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
              m[s[i]]++;
        }
        vector<int>v;

        for(auto a1:m)
        {
               v.push_back(a1.second);
        }
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        for(int i=0;i<v.size();i++)
        {
               int val=v[i];
               ans=min(ans,solve(v,k,val));

        }
        return ans;
        
    }
};