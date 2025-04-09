class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
               int minn=*min_element(nums.begin(),nums.end());
               if(k>minn)return -1;
               unordered_map<int,int>m;
               for(int i=0;i<nums.size();i++)
               {
                     m[nums[i]]++;
               }
               if(m.find(k)!=m.end())return m.size()-1;
               return m.size();
    }
};