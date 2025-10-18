class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
         sort(nums.begin(),nums.end());
         int possible=nums[0]-k+1;
       nums[0]=nums[0]-k;
   for(int i=1;i<nums.size();i++)
   {
            if((nums[i]-k)>=possible)
            {
                //  cout<<"j"<<possible<<" "<<nums[i]-k;
                nums[i]=max(possible,nums[i]-k);
           possible=nums[i]+1;
            }else if((nums[i]+k)>=possible)
            {
                  nums[i]=min(possible,nums[i]+k);
                  possible=nums[i]+1;
                //    cout<<"k";
            }
   }
    
set<int>s;
   for(int i=0;i<nums.size();i++)
   {
      
      s.insert(nums[i]);
   }
   return s.size();

    }
};
// 54 54 56 56