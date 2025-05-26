class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long num1=0;
        long long num2=0;
        int znum1=0;
        int znum2=0;
        for(int i=0;i<nums1.size();i++)
        {
                  if(nums1[i]==0)
                  znum1++;
                  num1+=nums1[i];
        }
         for(int i=0;i<nums2.size();i++)
        {
                  if(nums2[i]==0)
                  znum2++;
                  num2+=nums2[i];
        }
        if(num1==num2)
        {
            
               
               if(znum1==0&&znum2==0)return num1;
        }
     
         num1+=znum1;
         num2+=znum2;
            if(num1>num2&&znum2==0)
        {
            
                return -1;
        }
        if(num1<num2&&znum1==0)
        return -1;
         return max(num1,num2);
        
    }
};