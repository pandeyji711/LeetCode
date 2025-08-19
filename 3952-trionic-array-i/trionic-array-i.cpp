class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=2;
        int dub=nums[0];
        if(nums[1]<=dub)return 0;
        dub=nums[1];
        for(;i<nums.size();i++)
        {
               if(nums[i]==dub)return 0;
               if(nums[i]<dub)
               {
                  break;
               }
               dub=nums[i];
        }
         if(i+1>=nums.size())return 0;
        if(nums[i]==nums[i+1])return 0;
        dub=nums[i];
        i++;
        bool t=false;
          for(;i<nums.size();i++)
        {
               if(nums[i]==dub)return 0;
               if(nums[i]>dub)
               {
                t=true;
                  break;
               }
               dub=nums[i];
        }
         if(t==false)return 0;
           dub=nums[i];
           i++;
           for(;i<nums.size();i++)
        {
               if(nums[i]==dub)return 0;
               if(nums[i]<dub)
               {
                  return 0;
               }
               dub=nums[i];
        }
         return 1;

    }
};