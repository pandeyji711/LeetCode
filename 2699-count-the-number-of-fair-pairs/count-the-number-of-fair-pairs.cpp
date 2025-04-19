class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        //less then lower
        long long low=0;
        for(int i=1;i<nums.size();i++)
        {
              int maxx=lower-1-nums[i];
              auto it=upper_bound(nums.begin(),nums.begin()+i,maxx);
            //   if(it==nums.begin()+i)continue;
            if(maxx<nums[0])continue;
             int elements=0;
                   if(it==nums.begin()+i)
                   {
                     elements=it-nums.begin();
                   }else
                   elements=it-nums.begin();
                //    cout<<elements<<" ";
                //  cout<<elements<<" "<<i<<" "<<endl;
                    low+=elements;

              
              
        }
        //greater ten upper
        long long upr =0;
        for(int i=0;i<nums.size();i++)
        {
                int atlest=upper-nums[i];
                auto it=upper_bound(nums.begin()+i+1,nums.end(),atlest);
                if(it==nums.end())continue;
                else{
                        
                        int ele=nums.size()-(it-nums.begin());
                        // cout<<ele<<" "<<i<<" "<<it-nums.begin() <<endl;
                       upr+=ele;
                }
        }
        // cout<<low<<" "<<upr;
        long long  n=nums.size();
        long long total=n*(n-1)/2-(low+upr);
        return total; 
    }
};