class Solution {
public:
    
    
    int maximumLength(vector<int>& nums) {
          // 0 reminder
          int zerol=1;
          int odd=0;
           if(nums[0]%2!=0)
           odd=1;
           int k=0;
              int even=0;
             int odd1=0;
          for(int i=0;i<nums.size();i++)
          {
                 if(nums[i]%2!=odd)
                 {
                     k++;
                    odd=nums[i]%2;
                 }
                  if(nums[i]%2==0)
                 even++;
                 else
                 odd1++;


          }
          zerol+=k;
          even=max(even,odd1);
          return max(zerol,even);
    }
};