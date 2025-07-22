class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        unordered_map<int,int>m;
        int dub=0;
        int ans=0;
        int sc=0;
        while(r<nums.size())
        {
                 m[nums[r]]++;
                 if(m[nums[r]]==2)
                  dub++;
                 sc+=nums[r];
                //  cout<<dub<<" "<<r<<endl;
                 while(dub>0)
                 {
                       m[nums[l]]--;
                       if(m[nums[l]]==1)
                       dub--;
                        sc-=nums[l];
                       l++;
                      
                 }
                //  cout<<"Ew";
                  if(dub==0)
                  {
                    ans=max(sc,ans);
                  }
                 r++;
        }
        return ans;
    }
};