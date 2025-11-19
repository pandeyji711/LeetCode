class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool found=true;
        while(found)
        {  
             found=false;
               for(int i=0;i<nums.size();i++)
               {
                   if(original==nums[i])
                   {
                     original=original*2;
    
                      found=true;
                   }
               }
        }
        return original;
    }
};