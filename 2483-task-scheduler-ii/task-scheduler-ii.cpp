class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
         unordered_map<long long,long long>m;
         long long  ans=1;
         for( int t:tasks)
         {
               if(m.count(t)&&m[t]>ans)
               {
                   ans=m[t];

               }
               m[t]=ans+space+1;
               ans++;
         }
         return ans-1;
    }
};