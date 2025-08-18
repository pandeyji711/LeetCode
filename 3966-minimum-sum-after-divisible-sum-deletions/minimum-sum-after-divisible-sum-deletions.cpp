class Solution {
public:
   static bool com(const vector<long long >&a,const vector<long long >&b)
   {
        return a[0]<b[0];
   }
   
    long long solve( vector<vector<long long >>&v,int ind, vector<long long>&dp)
    {
                   if(ind>=v.size())
                   return 0;
            if(dp[ind]!=-1)
            {
                 return dp[ind];
            }
                   //take 
                   vector<long long>tem={v[ind][1],0,0};
                   auto it=lower_bound(v.begin(),v.end(),tem,com);
                   if(it==v.end())
                   return dp[ind]=max(v[ind][2],solve(v,ind+1,dp));

                   int index= it-v.begin();
                   long long  a=v[ind][2]+solve(v,index,dp);
                   long  long  b=solve(v,ind+1,dp);
                   return dp[ind]=max(a,b);

    }
    long long minArraySum(vector<int>& nums, int k) {
        
         vector<long long>pre(nums.size()+1,0);
         unordered_map<int,int>rem;
         rem[0]=0;
         for(int i=0;i<nums.size();i++)
         {
              pre[i+1]=pre[i]+nums[i];
            //   cout<<pre[i+1]<<" ";
         }
        //  cout<<endl;
         vector<vector<long long >>v;
         for(int i=1;i<pre.size();i++)
         {
               int re=pre[i]%k;
            //    cout<<re<<" ";/
               if(rem.count(re))
               {
                    int st=rem[re]+1;
                    int end=i+1;
                    v.push_back({st,end,pre[i]-pre[st-1]});
                    // cout<<st<<" "<<end<<" "<<pre[i]-pre[st]<<endl;
               }
               
               rem[re]=i;
         }
         sort(v.begin(),v.end(),com);
         vector<long long>dp(v.size()+1,-1);
         return pre[nums.size()]-solve(v,0,dp);
    }
};