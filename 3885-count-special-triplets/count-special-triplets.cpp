class Solution {
public:
 long long int mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        
      unordered_map<int,int>m;
      vector<int>left(nums.size(),0);
      vector<int>right(nums.size(),0);
      //left
      for(int i=0;i<nums.size();i++)
      {
                    if(m.find(2*nums[i])!=m.end())
                    {
                            left[i]=m[2*nums[i]];
                          
                    }
                    m[nums[i]]++;
      }
      m.clear();
        //right
      for(int i=nums.size()-1;i>=0;i--)
      {
                    if(m.find(2*nums[i])!=m.end())
                    {
                            right[i]=m[2*nums[i]];
                          
                    }
                    m[nums[i]]++;
      }
       int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            //   cout<<left[i]<<" "<<right[i]<<endl;
                  ans=(ans%mod+((left[i]%mod)*(right[i]%mod))%mod)%mod;
        }
        return ans%mod;
    }
};