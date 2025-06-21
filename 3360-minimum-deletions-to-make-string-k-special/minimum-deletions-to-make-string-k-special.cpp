class Solution {
public:
 int solve(vector<int>&v,int k,int val)
 {
     int ansl=0;
        int l=max(0,val-k);
        
          for(int i=0;i<v.size();i++)
          {
              if(v[i]==0)continue;
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
             if(v[i]==0)continue;
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
    vector<int>v(26,0);
        for(int i=0;i<s.length();i++)
        {
              v[s[i]-'a']++;
        }
        int ans=INT_MAX;
        for(int i=0;i<v.size();i++)
        {
              if(v[i]==0)continue;
               int val=v[i];
               ans=min(ans,solve(v,k,val));

        }
        return ans;
        
    }
};