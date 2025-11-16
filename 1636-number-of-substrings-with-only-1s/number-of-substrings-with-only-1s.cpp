class Solution {
public:
 long long int mod=1e9+7;
    int numSub(string s) {
        int cnt=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
               if(s[i]=='0'&&cnt>0)
               {
                     ans=(ans%mod+(cnt%mod*(cnt%mod+1)/2)%mod)%mod;
                  
                     cnt=0;
               }else if(s[i]=='1'){
                cnt++;
               }
        }

         if(cnt>0)
               {
                     ans=(ans%mod+(cnt%mod*(cnt%mod+1)/2)%mod)%mod;
                     cnt=0;
               }
        return ans;
    }
};