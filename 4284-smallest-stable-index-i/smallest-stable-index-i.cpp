class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxx(n,0);
        vector<int>minn(n,0);
        maxx[0]=nums[0];
        for(int i=1;i<n;i++)
        {
             maxx[i]=max(maxx[i-1],nums[i]);
        }
         minn[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
             minn[i]=min(minn[i+1],nums[i]);
        }
        for(int i=0;i<n;i++)
        {
             if(maxx[i]-minn[i]<=k)
             { 
             return i;
             }
             
        }
        return -1;
    }
};