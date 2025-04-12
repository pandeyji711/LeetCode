class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {

                for(int j=i;j<nums.size();j++)
                {
                       int nu=nums[i]^nums[j];
                       m[nu]++;

                }
        }
        unordered_map<int,int>ansm;
        for(int i=0;i<nums.size();i++)
        {
               for( auto &a1:m)
               {
                        int mu=a1.first^nums[i];
                        ansm[mu]++;
               }
        }
        return ansm.size();
    }
};