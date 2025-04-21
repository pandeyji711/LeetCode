class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int min=lower;
        int n=differences.size();
         vector<long long >v(n+1);
         v[0]=lower;
         long long  maxx=v[0];
         long long  minn=v[0];
         for(int i=0;i<differences.size();i++)
         {
                   v[i+1]=differences[i]+v[i];
                // cout<<v[i+1]<<" ";
                   maxx=max(maxx,v[i+1]);
                //    minn=min(minn,v[i+1]);
                if(minn>v[i+1])
                minn=v[i+1];
         }
         int ans=upper-maxx+1-(lower-minn);
         if(ans<0)return 0;
         return ans ;
    }
};