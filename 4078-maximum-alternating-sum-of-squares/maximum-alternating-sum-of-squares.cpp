class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        vector<int>v;
        for(int n:nums)
        {
              v.push_back(abs(n));
        }

        sort(v.begin(),v.end());
         int l=0;
        int r=v.size()-1;
        if(v.size()%2!=0)
        {
            r--;
           
        }
      
        while(l<r)
        {
              ans+=1ll*(1ll*pow(v[r],2)-1ll*pow(v[l],2));
              
            r--;
            l++;  
        }
        if(v.size()%2!=0)
        {
            ans+=1ll*pow(v[v.size()-1],2);
        }
        return ans;

    }
};