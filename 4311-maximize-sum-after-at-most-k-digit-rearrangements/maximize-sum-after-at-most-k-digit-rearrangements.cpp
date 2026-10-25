class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<pair<int,int>>v1;
        for(int i=0;i<nums.size();i++)
        {
                int nu=nums[i];
                int no=nu;
                vector<int>v;
                // cout<<no<<" "<<nu<<endl;
                while(nu>0)
                {
                      v.push_back(nu%10);
                      nu=nu/10;
                }
                sort(v.rbegin(),v.rend());
                int sum=0;
                for(int j=0;j<v.size();j++)
                {
                     sum=sum*10+v[j];
                }
                if(sum>no)
                v1.push_back({sum-nums[i],i});
        }
        long long ans=0;
        // cout<<v1[0].first<<endl;
        sort(v1.rbegin(),v1.rend());
        for(int i=0;i<min(k,(int)v1.size());i++)
        {
            // cout<<<<endl;
           ans+=(long long )v1[i].first+nums[v1[i].second]; 
             nums[v1[i].second]=0;
             cout<<v1[i].first<<endl;
             
        }
        for(int i=0;i<nums.size();i++)
        {
             ans+=nums[i];
        }
        return ans;
    }
};