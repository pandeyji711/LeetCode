class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long  long >v(n+1);
        v[0]=0;
        for(int i=0;i<n;i++)
        {
              v[i+1]=v[i]+nums[i];
        }
        int ans=0;
        for( int i=0;i<n-1;i++)
        {
              long first=v[i+1]-v[0];
              long last=v[n]-first;
            //   cout<<first<<" "<<last<<endl;
              if(first>=last)
              ans++;
        }
        return ans;
        
    }
};