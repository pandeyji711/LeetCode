class Solution {
public:
 long long mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<int,int>>act;
        queue<vector<int>>wait;
        int ans=0;
        wait.push({delay+1,forget+1,1});
    int  ac=0;
        for(int i=1;i<=n;i++)
        {
                while(!act.empty()&&act.front().first==i){
                
                // cout<<act.front().second<<" ";
               ac = ( (ac - act.front().second) % mod + mod ) % mod;
                act.pop();
                
                }
                if(!wait.empty()&&wait.front()[0]==i)
                {

                //    cout<<wait.front()[0]<<" "<<wait.front()[1]<<" "<<wait.front()[2]<<endl;
                     act.push({wait.front()[1],wait.front()[2]});
                     ac=(ac%mod+wait.front()[2]%mod)%mod;
                     wait.pop();
                }
        //  cout<<act.size()<<" "<<i<<endl;
          if(act.size()>0){
           
            wait.push({delay+i,forget+i,ac});
          }
          
        }
        while(!wait.empty())
        {
               ans=(ans%mod+wait.front()[2]%mod)%mod;
               wait.pop();
        }
         while(!act.empty())
        {
               ans=(ans%mod+act.front().second%mod)%mod;
               act.pop();
        }
        return ans%mod;
    }
};