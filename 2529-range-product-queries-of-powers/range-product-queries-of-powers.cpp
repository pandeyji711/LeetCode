class Solution {
public:

   long long const mod= 1e9+7;
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
           
            int n1=n;
            vector<long long>v;
            int p=0;
            while(n1)
            {
                  if(n1&1)
                  {
                       v.push_back(pow(2,p));
                  }
               n1=n1>>1;
               p++;
            }
               
                vector<int>ans;
            
                for(int i=0;i<queries.size();i++)
                {
                      int sum=1;
                          for(int j=queries[i][0];j<=queries[i][1];j++ )
                          {
                                  sum=((sum%mod)*v[j]%mod)%mod;
                          }
                          ans.push_back(sum);
                }
                return ans;
             
    }
};