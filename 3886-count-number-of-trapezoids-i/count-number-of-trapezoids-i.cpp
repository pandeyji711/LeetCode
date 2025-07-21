class Solution {
public:
  long long mod =1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
               unordered_map<int,int>m;
               for(int i=0;i<points.size();i++)
               {
                         m[points[i][1]]++;
               }
             vector<int>v;
            vector<int>pre;
            pre.push_back(0);
             for( auto &a:m)
             {
                  if(a.second>1){
                    // cout<<a.second<<" ";
                   int fac=(((a.second-1)%mod)*((a.second)%mod)/2)%mod;
                   int pro=((pre[pre.size()-1]%mod)+(fac%mod))%mod;
                   pre.push_back(pro);
                   v.push_back(a.second);
                  }
             }
             int ans=0;
             if(pre.size()<3)return 0;
             for(int i=0;i<v.size();i++)
             {
                   int sum=pre[pre.size()-1]-pre[i+1];

                     int fac=(((v[i]-1)%mod)*((v[i])%mod)/2)%mod;
                      ans=((ans%mod)+((fac%mod)*(sum)%mod)%mod)%mod;
             }
             return ans;


    }
};