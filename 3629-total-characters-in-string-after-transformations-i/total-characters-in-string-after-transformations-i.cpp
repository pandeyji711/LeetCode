class Solution {
public:
   long long mod=1e9+7;
   int dp[1000000];
     int solve(int t)
     {
          if(t<25)return 1;
            int a=0;
            int b=0;
            // cout<<-1;
            if(dp[t]!=-1)return dp[t]%mod;
            if(t-26>=0)
            a=solve(t-26)%mod;
         
           
            b=solve(t-25)%mod;
           
            return dp[t]=(a+b)%mod;

     }
    //     int solve(int t)
    //  {
    //       if(t<25)return 1;
    //         int a=0;
    //         int b=0;
    //         if(t-26>=0)
    //         a=solve(t-26);
         
           
    //         b=solve(t-25);
           
    //         return a+b;

    //  }
    int lengthAfterTransformations(string s, int t) {
        int ans=0;
        //   cout<<solve(t+2)<<endl;
        memset(dp,-1,sizeof(dp));
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
                 if(m.find(s[i])!=m.end())
                 {
                        ans=ans%mod+m[s[i]]%mod;
                 }else{
                int x=s[i]-'a';
                int z='z'-'a';
                int sc=(solve(t+x))%mod;
                 ans=ans%mod+sc;
                 m[s[i]]=sc;
                 }
              

        }
        return ans%mod;
    }
};